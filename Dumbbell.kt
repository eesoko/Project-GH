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

private enum class MotionState {
    READY,
    LIFTING,
    LOWERING
}

class MainActivity : ComponentActivity(), SensorEventListener {

    private lateinit var sensorManager: SensorManager
    private var gyroscope: Sensor? = null

    private val _repCount = MutableStateFlow(0)
    val repCount: StateFlow<Int> = _repCount

    private var motionState = MotionState.READY

    private val liftingThreshold = 1.5f   // 기존 1.5f -> 1.0f
    private val loweringThreshold = -1.0f  // 기존 -1.0f -> -0.8f

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        sensorManager = getSystemService(Context.SENSOR_SERVICE) as SensorManager
        gyroscope = sensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE)
        setContent {
            val count by repCount.collectAsState()
            CounterScreen(count = count)
        }
    }

    override fun onResume() {
        super.onResume()
        gyroscope?.also { gyro ->
            sensorManager.registerListener(this, gyro, SensorManager.SENSOR_DELAY_GAME)
        }
    }

    override fun onPause() {
        super.onPause()
        sensorManager.unregisterListener(this)
    }

    override fun onSensorChanged(event: SensorEvent?) {
        if (event?.sensor?.type != Sensor.TYPE_GYROSCOPE) return

        val gyroY = event.values[1]

        when (motionState) {
            MotionState.READY -> {
                if (gyroY > liftingThreshold) {
                    motionState = MotionState.LIFTING
                }
            }
            MotionState.LIFTING -> {
                if (gyroY < loweringThreshold) {
                    motionState = MotionState.LOWERING
                }
            }
            MotionState.LOWERING -> {
                _repCount.value++
                motionState = MotionState.READY
            }
        }

        Log.d("DumbbellCurl", "State: $motionState, GyroY: ${"%.2f".format(gyroY)}")
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
        Text(
            text = "덤벨 컬",
            fontSize = 30.sp,
            fontWeight = FontWeight.Normal,
            color = MaterialTheme.colors.onBackground // 배경에 맞는 색상
        )
        Spacer(modifier = Modifier.height(8.dp)) // 텍스트와 숫자 사이에 간격 추가
        Text(
            text = count.toString(),
            fontSize = 80.sp,
            fontWeight = FontWeight.Bold
        )
    }
}