package com.example.geunhwang.presentation

import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.wear.compose.material.*
import androidx.wear.compose.navigation.SwipeDismissableNavHost
import androidx.wear.compose.navigation.composable
import androidx.wear.compose.navigation.rememberSwipeDismissableNavController
import com.example.geunhwang.presentation.theme.GeunHwangTheme
import kotlinx.coroutines.flow.StateFlow

class MainActivity : ComponentActivity(), SensorEventListener {

    private lateinit var sensorManager: SensorManager
    private var accelerometer: Sensor? = null
    private var gyroscope: Sensor? = null

    // ViewModel을 클래스 레벨에서 참조
    private lateinit var viewModel: MainViewModel

    // 두 센서의 최신 값을 저장하기 위한 변수
    private var lastAccelData = FloatArray(3)
    private var lastGyroData = FloatArray(3)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        sensorManager = getSystemService(Context.SENSOR_SERVICE) as SensorManager
        accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
        gyroscope = sensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE)

        setContent {
            // Composable 함수 안에서 viewModel 인스턴스를 초기화하고 클래스 변수에 할당
            this.viewModel = viewModel()

            GeunHwangTheme {
                WearAppNavigation(viewModel = this.viewModel)
            }
        }
    }

    override fun onResume() {
        super.onResume()
        registerSensors()
    }

    override fun onPause() {
        super.onPause()
        unregisterSensors()
    }

    // onResume/onPause 시 센서 리스너 등록 및 해제
    private fun registerSensors() {
        accelerometer?.also { sensor ->
            sensorManager.registerListener(this, sensor, SensorManager.SENSOR_DELAY_GAME)
        }
        gyroscope?.also { sensor ->
            sensorManager.registerListener(this, sensor, SensorManager.SENSOR_DELAY_GAME)
        }
    }
    private fun unregisterSensors() {
        sensorManager.unregisterListener(this)
    }

    // 센서 값이 변경될 때마다 ViewModel에 데이터 전달
    override fun onSensorChanged(event: SensorEvent?) {
        val ts = event?.timestamp ?: return

        // 최신 센서 값 업데이트
        when (event.sensor.type) {
            Sensor.TYPE_ACCELEROMETER -> lastAccelData = event.values.clone()
            Sensor.TYPE_GYROSCOPE -> lastGyroData = event.values.clone()
        }

        // 두 센서의 최신 값을 묶어서 ViewModel에 전달
        if (::viewModel.isInitialized) {
            viewModel.onSensorDataChanged(ts, lastAccelData, lastGyroData)
        }
    }

    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {}
}

// --- 아래 UI 코드는 변경할 필요 없습니다 ---

@Composable
fun WearAppNavigation(viewModel: MainViewModel) {
    val navController = rememberSwipeDismissableNavController()
    // isDataCollectionMode 상태를 ViewModel로부터 받음
    val isDataCollectionMode by viewModel.isDataCollectionMode.collectAsState()

    SwipeDismissableNavHost(
        navController = navController,
        startDestination = "main_screen"
    ) {
        composable("main_screen") {
            MainScreen(
                onDumbbellCurlClick = {
                    viewModel.setDataCollectionMode(false)
                    viewModel.onExerciseSelected(ExerciseType.DUMBBELL_CURL)
                    navController.navigate("counter_screen/${ExerciseType.DUMBBELL_CURL}")
                },
                onSquatClick = {
                    viewModel.setDataCollectionMode(false)
                    viewModel.onExerciseSelected(ExerciseType.SQUAT)
                    navController.navigate("counter_screen/${ExerciseType.SQUAT}")
                },
                onDataCollectionClick = {
                    viewModel.setDataCollectionMode(true)
                    navController.navigate("collection_selection_screen")
                }
            )
        }

        composable("collection_selection_screen") {
            ExerciseSelectionScreen { exerciseName ->
                viewModel.onExerciseSelected(exerciseName)
                navController.navigate("logging_screen/$exerciseName")
            }
        }

        composable("logging_screen/{exerciseName}") { backStackEntry ->
            val exerciseName = backStackEntry.arguments?.getString("exerciseName") ?: "기록 중"
            LoggingScreen(
                exerciseName = exerciseName,
                onStopLoggingClick = {
                    viewModel.onWorkoutEnd()
                    navController.popBackStack()
                }
            )
        }

        composable("counter_screen/{exerciseName}") { backStackEntry ->
            val exerciseName = backStackEntry.arguments?.getString("exerciseName") ?: "운동"
            val repCount by viewModel.repCount.collectAsState()

            CounterScreen(
                exerciseName = exerciseName,
                count = repCount,
                onEndWorkoutClick = {
                    viewModel.onWorkoutEnd()
                    navController.popBackStack()
                }
            )
        }
    }
}


@Composable
fun MainScreen(
    onDumbbellCurlClick: () -> Unit,
    onSquatClick: () -> Unit,
    onDataCollectionClick: () -> Unit
) {
    Column(
        modifier = Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Button(onClick = onDumbbellCurlClick) { Text("덤벨 컬") }
        Spacer(modifier = Modifier.height(10.dp))
        Button(onClick = onSquatClick) { Text("스쿼트") }
        Spacer(modifier = Modifier.height(20.dp))
        Button(
            onClick = onDataCollectionClick,
            colors = ButtonDefaults.buttonColors(backgroundColor = Color.DarkGray)
        ) {
            Text("데이터 수집 모드")
        }
    }
}

@Composable
fun ExerciseSelectionScreen(onExerciseSelected: (String) -> Unit) {
    // 여기에 데이터 수집할 운동 목록을 추가하면 됩니다.
    ScalingLazyColumn(
        modifier = Modifier.fillMaxSize(),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        item { Text(text = "수집할 운동 선택", modifier = Modifier.padding(bottom = 16.dp)) }
        item { Button(onClick = { onExerciseSelected("Overhead Press") }) { Text("오버헤드 프레스") } }
        item { Spacer(modifier = Modifier.height(8.dp)) }
        item { Button(onClick = { onExerciseSelected("Push Up") }) { Text("푸시업") } }
    }
}

@Composable
fun LoggingScreen(exerciseName: String, onStopLoggingClick: () -> Unit) {
    Column(
        modifier = Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(text = exerciseName, fontSize = 24.sp)
        Text(text = "데이터 기록 중...", fontSize = 20.sp, color = Color.Green)
        Spacer(modifier = Modifier.height(20.dp))
        Button(
            onClick = onStopLoggingClick,
            colors = ButtonDefaults.buttonColors(backgroundColor = MaterialTheme.colors.error)
        ) {
            Text("기록 중지")
        }
    }
}

@Composable
fun CounterScreen(exerciseName: String, count: Int, onEndWorkoutClick: () -> Unit) {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.SpaceAround
    ) {
        Text(text = exerciseName, fontSize = 22.sp)
        Text(text = count.toString(), fontSize = 72.sp, fontWeight = FontWeight.Bold)
        Button(
            onClick = onEndWorkoutClick,
            colors = ButtonDefaults.buttonColors(backgroundColor = MaterialTheme.colors.error)
        ) {
            Text("운동 종료")
        }
    }
}