package com.example.geunhwang.presentation

import android.app.Application
import androidx.lifecycle.AndroidViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow

class MainViewModel(application: Application) : AndroidViewModel(application) {

    private val _repCount = MutableStateFlow(0)
    val repCount = _repCount.asStateFlow()
    private val _currentExercise = MutableStateFlow<String?>(null)
    val currentExercise = _currentExercise.asStateFlow()
    private val _isDataCollectionMode = MutableStateFlow(false)
    val isDataCollectionMode = _isDataCollectionMode.asStateFlow()

    private val dataLogger = SensorDataLogger(application)

    // TODO: SensorRepository 관련 로직 추가 예정

    fun setDataCollectionMode(isCollecting: Boolean) {
        _isDataCollectionMode.value = isCollecting
    }

    fun onExerciseSelected(exerciseType: String) {
        _currentExercise.value = exerciseType
        _repCount.value = 0
        if (_isDataCollectionMode.value) {
            dataLogger.startLogging(exerciseType)
        }
    }

    fun onWorkoutEnd() {
        if (_isDataCollectionMode.value) {
            dataLogger.stopLogging()
        }
        _currentExercise.value = null
    }

    // MainActivity로부터 센서 데이터를 전달받는 함수
    fun onSensorDataChanged(timestamp: Long, accel: FloatArray, gyro: FloatArray) {
        if (_isDataCollectionMode.value && _currentExercise.value != null) {
            dataLogger.logData(timestamp, accel, gyro)
        } else {
            // TODO: 카운팅 모드일 때의 알고리즘 실행
        }
    }
}