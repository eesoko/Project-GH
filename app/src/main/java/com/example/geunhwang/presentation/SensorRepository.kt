package com.example.geunhwang.presentation

import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager

class SensorRepository(context: Context) : SensorEventListener {

    var onRepDetected: (() -> Unit)? = null

    private var sensorManager: SensorManager =
        context.getSystemService(Context.SENSOR_SERVICE) as SensorManager

    // --- 👇👇 1. 양쪽 센서 모두를 변수로 선언 👇👇 ---
    private var accelerometer: Sensor? =
        sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
    private var gyroscope: Sensor? =
        sensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE)

    // --- 👇👇 2. SensorDataLogger 인스턴스 추가 👇👇 ---
    private val sensorDataLogger = SensorDataLogger(context)
    private var isDataCollectionMode = false
    // ----------------------------------------------------

    // --- 👇👇 3. 마지막 센서 값을 저장할 변수 추가 👇👇 ---
    private var lastAccelData = floatArrayOf(0f, 0f, 0f)
    private var lastGyroData = floatArrayOf(0f, 0f, 0f)
    // ----------------------------------------------------

    private var currentExercise: String? = null

    private var dumbbellCurlState = DumbbellCurlState.READY
    private val gyroThresholdUp = 1.0f
    private val gyroThresholdDown = -0.8f

    private var squatState = SquatState.READY
    private val accelThresholdDown = -2.5f
    private val accelThresholdUp = 1.8f

    // --- 👇👇 4. startListening 함수가 isCollecting 파라미터를 받도록 수정 👇👇 ---
    fun startListening(exerciseType: String, isCollecting: Boolean) {
        currentExercise = exerciseType
        isDataCollectionMode = isCollecting // 모드 저장

        dumbbellCurlState = DumbbellCurlState.READY
        squatState = SquatState.READY

        if (isDataCollectionMode) {
            // 데이터 수집 모드일 경우: 양쪽 센서 모두 켜고 로깅 시작
            sensorDataLogger.startLogging(exerciseType)
            accelerometer?.let { sensorManager.registerListener(this, it, SensorManager.SENSOR_DELAY_UI) }
            gyroscope?.let { sensorManager.registerListener(this, it, SensorManager.SENSOR_DELAY_UI) }
        } else {
            // 카운팅 모드일 경우: 기존 로직대로 필요한 센서만 켜기
            when (exerciseType) {
                ExerciseType.DUMBBELL_CURL -> gyroscope?.let {
                    sensorManager.registerListener(this, it, SensorManager.SENSOR_DELAY_GAME)
                }
                ExerciseType.SQUAT -> accelerometer?.let {
                    sensorManager.registerListener(this, it, SensorManager.SENSOR_DELAY_GAME)
                }
            }
        }
    }

    fun stopListening() {
        sensorManager.unregisterListener(this)
        // --- 👇👇 5. 데이터 수집 모드였다면 로깅 중지 👇👇 ---
        if (isDataCollectionMode) {
            sensorDataLogger.stopLogging()
        }
        currentExercise = null
    }

    override fun onSensorChanged(event: SensorEvent?) {
        if (event == null) return

        // --- 👇👇 6. 데이터 수집 모드일 때와 아닐 때를 분리 👇👇 ---
        if (isDataCollectionMode) {
            // 데이터 수집 모드: 최신 센서 값을 업데이트하고 파일에 기록
            val timestamp = System.currentTimeMillis()
            when (event.sensor.type) {
                Sensor.TYPE_ACCELEROMETER -> lastAccelData = event.values.clone()
                Sensor.TYPE_GYROSCOPE -> lastGyroData = event.values.clone()
            }
            sensorDataLogger.logData(timestamp, lastAccelData, lastGyroData)
        } else {
            // 카운팅 모드: 기존처럼 운동별 알고리즘 실행
            when (currentExercise) {
                ExerciseType.DUMBBELL_CURL -> runDumbbellCurlAlgorithm(event)
                ExerciseType.SQUAT -> runSquatAlgorithm(event)
            }
        }
    }

    // (runDumbbellCurlAlgorithm, runSquatAlgorithm, onAccuracyChanged 함수는 수정 없음)
    // ... (기존 코드와 동일) ...
    private fun runDumbbellCurlAlgorithm(event: SensorEvent?) {
        if (event?.sensor?.type != Sensor.TYPE_GYROSCOPE) return
        val gyroY = event.values[1]

        when (dumbbellCurlState) {
            DumbbellCurlState.READY -> if (gyroY > gyroThresholdUp) dumbbellCurlState = DumbbellCurlState.LIFTING
            DumbbellCurlState.LIFTING -> if (gyroY < gyroThresholdDown) dumbbellCurlState = DumbbellCurlState.LOWERING
            DumbbellCurlState.LOWERING -> {
                onRepDetected?.invoke()
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
                onRepDetected?.invoke()
                squatState = SquatState.READY
            }
        }
    }

    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {}
}