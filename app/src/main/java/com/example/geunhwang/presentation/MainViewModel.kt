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

    // SensorRepository를 고용합니다.
    private val sensorRepository = SensorRepository(context = application)

    init {
        // SensorRepository로부터 보고를 받을 통신 채널을 연결합니다.
        sensorRepository.onRepDetected = {
            _repCount.value++
        }
    }

    fun onExerciseSelected(exerciseType: String) {
        _currentExercise.value = exerciseType
        _repCount.value = 0
        sensorRepository.startListening(exerciseType) // SensorRepository에게 센서 작동 시작을 지시
    }

    fun onWorkoutEnd() {
        sensorRepository.stopListening() // SensorRepository에게 센서 작동 중지를 지시
        _currentExercise.value = null
    }
}