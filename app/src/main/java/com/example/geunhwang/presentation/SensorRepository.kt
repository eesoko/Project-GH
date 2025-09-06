package com.example.geunhwang.presentation

import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager

class SensorRepository(context: Context) : SensorEventListener {

    // ViewModel에게 "횟수 1회 감지됨!"이라고 보고할 통신 채널
    var onRepDetected: (() -> Unit)? = null

    private var sensorManager: SensorManager =
        context.getSystemService(Context.SENSOR_SERVICE) as SensorManager
    private var accelerometer: Sensor? =
        sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
    private var gyroscope: Sensor? =
        sensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE)

    private var currentExercise: String? = null

    // 각 운동별 알고리즘 변수들
    private var dumbbellCurlState = DumbbellCurlState.READY
    private val gyroThresholdUp = 1.0f
    private val gyroThresholdDown = -0.8f

    private var squatState = SquatState.READY
    private val accelThresholdDown = -2.5f
    private val accelThresholdUp = 1.8f

    fun startListening(exerciseType: String) {
        currentExercise = exerciseType
        // 운동에 필요한 센서만 켭니다.
        when (exerciseType) {
            ExerciseType.DUMBBELL_CURL -> gyroscope?.let {
                sensorManager.registerListener(this, it, SensorManager.SENSOR_DELAY_GAME)
            }
            ExerciseType.SQUAT -> accelerometer?.let {
                sensorManager.registerListener(this, it, SensorManager.SENSOR_DELAY_GAME)
            }
        }
    }

    fun stopListening() {
        sensorManager.unregisterListener(this)
        currentExercise = null
    }

    override fun onSensorChanged(event: SensorEvent?) {
        // 현재 선택된 운동에 따라 알맞은 알고리즘을 실행합니다.
        when (currentExercise) {
            ExerciseType.DUMBBELL_CURL -> runDumbbellCurlAlgorithm(event)
            ExerciseType.SQUAT -> runSquatAlgorithm(event)
        }
    }

    private fun runDumbbellCurlAlgorithm(event: SensorEvent?) {
        if (event?.sensor?.type != Sensor.TYPE_GYROSCOPE) return
        val gyroY = event.values[1]

        when (dumbbellCurlState) {
            DumbbellCurlState.READY -> if (gyroY > gyroThresholdUp) dumbbellCurlState = DumbbellCurlState.LIFTING
            DumbbellCurlState.LIFTING -> if (gyroY < gyroThresholdDown) dumbbellCurlState = DumbbellCurlState.LOWERING
            DumbbellCurlState.LOWERING -> {
                onRepDetected?.invoke() // ViewModel에 보고!
                dumbbellCurlState = DumbbellCurlState.READY
            }
        }
    }

    private fun runSquatAlgorithm(event: SensorEvent?) {
        if (event?.sensor?.type != Sensor.TYPE_ACCELEROMETER) return
        val accelY = event.values[1]

        when (squatState) {
            SquatState.READY -> if (accelY < accelThresholdDown) squatState = SquatState.DESCENDING
            SquatState.DESCENDING -> if (accelY > accelThresholdUp) squatState = SquatState.ASCENDING
            SquatState.ASCENDING -> {
                onRepDetected?.invoke() // ViewModel에 보고!
                squatState = SquatState.READY
            }
        }
    }

    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {}
}