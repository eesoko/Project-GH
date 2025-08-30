package com.example.geunhwang.presentation

import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.wear.compose.material.MaterialTheme
import androidx.wear.compose.material.Text
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlin.math.abs
import kotlin.math.sqrt

// 피크 감지를 위한 상태 정의
private enum class PeakState {
    IDLE,               // 하강 피크를 기다리는 상태
    WAITING_FOR_ASCENT  // 하강 피크를 찾았고, 이제 상승 피크를 기다리는 상태
}

class MainActivity : ComponentActivity(), SensorEventListener {

    private lateinit var sensorManager: SensorManager
    private var accelerometer: Sensor? = null

    // UI와 연결된 최종 횟수
    private val _repCount = MutableStateFlow(0)
    val repCount: StateFlow<Int> = _repCount

    // --- 👇👇 새로운 지능형 알고리즘 변수들 👇👇 ---
    // 상태 관리
    private var peakState = PeakState.IDLE
    private var descentPeakTimeNs = 0L

    // 전처리
    private val g = floatArrayOf(0f, 0f, 0f) // 중력 추정값

    // 동적 임계치 (Adaptive Threshold)
    private var emaAmp = 0f
    private val emaBeta = 0.05f

    // 노이즈 제거 (Noise Rejection)
    private var lastCountTimeNs = 0L
    private val refractoryNs = 400_000_000L      // 최소 반복 간격 (0.4초)
    private val minRepTimeNs = 200_000_000L       // 하강-상승 피크 최소 시간 (0.2초)
    private val maxRepTimeNs = 1_500_000_000L      // 하강-상승 피크 최대 시간 (1.5초)
    // --- 👆👆 여기까지 👆👆 ---


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        sensorManager = getSystemService(Context.SENSOR_SERVICE) as SensorManager
        accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
        setContent {
            val count by repCount.collectAsState()
            CounterScreen(count = count)
        }
    }

    override fun onResume() {
        super.onResume()
        accelerometer?.also { accel ->
            sensorManager.registerListener(this, accel, SensorManager.SENSOR_DELAY_GAME)
        }
    }

    override fun onPause() {
        super.onPause()
        sensorManager.unregisterListener(this)
    }

    override fun onSensorChanged(event: SensorEvent?) {
        if (event?.sensor?.type != Sensor.TYPE_ACCELEROMETER) return
        val ts = event.timestamp

        // 1. 전처리: 중력 제거하여 순수 Y축 움직임(ly) 추출
        val ax = event.values[0]; val ay = event.values[1]; val az = event.values[2]
        val alphaLP = 0.1f
        g[0] = alphaLP * g[0] + (1 - alphaLP) * ax
        g[1] = alphaLP * g[1] + (1 - alphaLP) * ay
        g[2] = alphaLP * g[2] + (1 - alphaLP) * az
        val ly = ay - g[1]

        // 2. 동적 임계치 계산
        emaAmp = (1 - emaBeta) * emaAmp + emaBeta * abs(ly)
        val threshold = (0.6f * emaAmp).coerceAtLeast(1.8f) // 최소 1.8 m/s²의 기준 설정

        // 3. 핵심 로직: 피크 페어 매칭
        when (peakState) {
            // 하강 피크 (Trough)를 기다리는 상태
            PeakState.IDLE -> {
                if (ly < -threshold) { // 음수 기준치를 넘으면 하강 피크로 간주
                    peakState = PeakState.WAITING_FOR_ASCENT
                    descentPeakTimeNs = ts
                }
            }
            // 상승 피크 (Peak)를 기다리는 상태
            PeakState.WAITING_FOR_ASCENT -> {
                if (ly > threshold) { // 양수 기준치를 넘으면 상승 피크로 간주
                    val repTime = ts - descentPeakTimeNs

                    // 템포 가드: 너무 빠르거나 느린 동작은 무시
                    if (repTime in minRepTimeNs..maxRepTimeNs) {
                        // 불응기: 이전 카운트 후 충분한 시간이 지났는지 확인
                        if (ts - lastCountTimeNs > refractoryNs) {
                            _repCount.value++
                            lastCountTimeNs = ts
                        }
                    }
                    // 상태 초기화
                    peakState = PeakState.IDLE
                }
                
                // 타임아웃: 하강 피크 후 너무 오래 상승 피크가 없으면 초기화
                if (ts - descentPeakTimeNs > maxRepTimeNs) {
                    peakState = PeakState.IDLE
                }
            }
        }
        Log.d("SquatSmartCounter", "State: $peakState, ly: ${"%.2f".format(ly)}, Threshold: ${"%.2f".format(threshold)}")
    }

    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {}
}

@Composable
fun CounterScreen(count: Int) {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .background(MaterialTheme.colors.background)
            .padding(16.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(text = "스쿼트", fontSize = 30.sp)
        Spacer(modifier = Modifier.height(8.dp))
        Text(text = count.toString(), fontSize = 80.sp, fontWeight = FontWeight.Bold)
    }
}