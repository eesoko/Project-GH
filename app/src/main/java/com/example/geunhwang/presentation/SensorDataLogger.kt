package com.example.geunhwang.presentation

import android.content.Context
import java.io.File
import java.io.FileWriter
import java.text.SimpleDateFormat
import java.util.Date
import java.util.Locale

// 파일 쓰기를 전담하는 클래스
class SensorDataLogger(private val context: Context) {

    private var fileWriter: FileWriter? = null

    // 데이터 기록 시작: 운동 이름을 받아 CSV 파일 생성
    fun startLogging(exerciseName: String) {
        try {
            val timestamp = SimpleDateFormat("yyyyMMdd_HHmmss", Locale.getDefault()).format(Date())
            val fileName = "${exerciseName}_${timestamp}.csv"
            val file = File(context.filesDir, fileName) // 앱 내부 저장소에 파일 생성

            fileWriter = FileWriter(file)
            // CSV 파일의 헤더(첫 줄)를 작성
            fileWriter?.append("timestamp,ax,ay,az,gx,gy,gz\n")
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    // 데이터 기록 중지: 파일 닫기
    fun stopLogging() {
        try {
            fileWriter?.flush()
            fileWriter?.close()
            fileWriter = null
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    // 센서 데이터를 파일에 한 줄씩 쓰기
    fun logData(timestamp: Long, accel: FloatArray, gyro: FloatArray) {
        try {
            fileWriter?.append("$timestamp,${accel[0]},${accel[1]},${accel[2]},${gyro[0]},${gyro[1]},${gyro[2]}\n")
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }
}