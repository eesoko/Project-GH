package com.example.geunhwang.presentation

import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager

// 센서 데이터를 전문적으로 다루는 '창고 관리인' 클래스
class SensorRepository(
    context: Context,
    private val onRepDetected: (String) -> Unit // 횟수가 감지되면 ViewModel에 보고하는 함수
) : SensorEventListener {

    private var sensorManager: SensorManager =
        context.getSystemService(Context.SENSOR_SERVICE) as SensorManager

    private var accelerometer: Sensor? =
        sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
    private var gyroscope: Sensor? =
        sensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE)

    // 각 운동별 알고리즘 변수들
    private var dumbbellCurlState = DumbbellCurlState.READY
    private val gyroThresholdUp = 1.0f
    private val gyroThresholdDown = -0.8f

    private var squatState = SquatState.READY
    private val accelThresholdDown = -2.5f
    private val accelThresholdUp = 1.8f

    fun startListening() {
        accelerometer?.let {
            sensorManager.registerListener(this, it, SensorManager.SENSOR_DELAY_GAME)
        }
        gyroscope?.let {
            sensorManager.registerListener(this, it, SensorManager.SENSOR_DELAY_GAME)
        }
    }

    fun stopListening() {
        sensorManager.unregisterListener(this)
    }

    override fun onSensorChanged(event: SensorEvent?) {
        // ViewModel로부터 전달받은 운동 종류에 따라 알고리즘 실행
        // (이 부분은 다음 단계에서 ViewModel과 연결하며 완성됩니다)
        // 임시로 덤벨 컬 로직만 넣어두겠습니다.
        if (event?.sensor?.type != Sensor.TYPE_GYROSCOPE) return
        val gyroY = event.values[1]

        when (dumbbellCurlState) {
            DumbbellCurlState.READY -> if (gyroY > gyroThresholdUp) dumbbellCurlState = DumbbellCurlState.LIFTING
            DumbbellCurlState.LIFTING -> if (gyroY < gyroThresholdDown) dumbbellCurlState = DumbbellCurlState.LOWERING
            DumbbellCurlState.LOWERING -> {
                onRepDetected(ExerciseType.DUMBBELL_CURL) // ViewModel에 "덤벨 컬 1회 감지!" 보고
                dumbbellCurlState = DumbbellCurlState.READY
            }
        }
    }

    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {}
}

// (참고용) 이 파일 밖, 혹은 별도 파일에 두는 것이 좋습니다.
private enum class DumbbellCurlState { READY, LIFTING, LOWERING }
private enum class SquatState { READY, DESCENDING, ASCENDING }
object ExerciseType {
    const val DUMBBELL_CURL = "Dumbbell Curl"
    const val SQUAT = "Squat"
}