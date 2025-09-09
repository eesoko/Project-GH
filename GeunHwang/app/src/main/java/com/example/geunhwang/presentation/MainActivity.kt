package com.example.geunhwang.presentation

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.wear.compose.foundation.lazy.ScalingLazyColumn
import androidx.wear.compose.foundation.lazy.items
import androidx.wear.compose.material.Button
import androidx.wear.compose.material.ButtonDefaults
import androidx.wear.compose.material.MaterialTheme
import androidx.wear.compose.material.Text
import androidx.wear.compose.navigation.SwipeDismissableNavHost
import androidx.wear.compose.navigation.composable
import androidx.wear.compose.navigation.rememberSwipeDismissableNavController
import com.example.geunhwang.presentation.theme.GeunHwangTheme
import java.text.SimpleDateFormat
import java.util.Date
import java.util.Locale

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            val viewModel: MainViewModel = viewModel()
            GeunHwangTheme {
                WearAppNavigation(viewModel = viewModel)
            }
        }
    }
}

@Composable
fun WearAppNavigation(viewModel: MainViewModel) {
    val navController = rememberSwipeDismissableNavController()
    val repCount by viewModel.repCount.collectAsState()

    // --- 1. ViewModel로부터 '오늘의 운동' 목록을 실시간으로 받아옵니다. ---
    val todaySets by viewModel.todaySets.collectAsState()

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
                },
                // --- 2. '오늘의 운동 기록' 화면으로 이동하는 버튼에 대한 동작을 추가합니다. ---
                onTodayWorkoutClick = {
                    navController.navigate("today_workout_screen")
                }
            )
        }

        // --- 3. '오늘의 운동 기록'을 보여줄 새로운 화면(Composable)을 추가합니다. ---
        composable("today_workout_screen") {
            TodayWorkoutScreen(sets = todaySets)
        }

        // --- 이하 기존 화면들 ---

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
            CounterScreen(
                exerciseName = exerciseName,
                count = repCount,
                // --- 4. '세트 종료'와 '전체 운동 종료' 버튼에 ViewModel의 함수를 연결합니다. ---
                onSetCompleteClick = {
                    viewModel.onSetComplete()
                },
                onEndWorkoutClick = {
                    viewModel.onWorkoutEnd()
                    navController.popBackStack() // 메인 화면으로 복귀
                }
            )
        }
    }
}

// --- 👇👇 UI 컴포넌트(Composable 함수) 수정 및 추가 👇👇 ---

@Composable
fun MainScreen(
    onDumbbellCurlClick: () -> Unit,
    onSquatClick: () -> Unit,
    onDataCollectionClick: () -> Unit,
    onTodayWorkoutClick: () -> Unit // --- 5. 새로운 버튼을 위한 파라미터 추가 ---
) {
    Column(
        modifier = Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        // --- 6. '오늘의 운동 기록' 버튼을 새로 추가합니다. ---
        Button(onClick = onTodayWorkoutClick, colors = ButtonDefaults.buttonColors(backgroundColor = Color.Blue)) {
            Text("오늘의 운동 기록")
        }
        Spacer(modifier = Modifier.height(16.dp))
        Button(onClick = onDumbbellCurlClick) { Text("덤벨 컬") }
        Spacer(modifier = Modifier.height(8.dp))
        Button(onClick = onSquatClick) { Text("스쿼트") }
        Spacer(modifier = Modifier.height(16.dp))
        Button(
            onClick = onDataCollectionClick,
            colors = ButtonDefaults.buttonColors(backgroundColor = Color.DarkGray)
        ) {
            Text("데이터 수집")
        }
    }
}

@Composable
fun CounterScreen(
    exerciseName: String,
    count: Int,
    onSetCompleteClick: () -> Unit, // --- 7. '세트 종료' 버튼용 파라미터로 변경 ---
    onEndWorkoutClick: () -> Unit // '전체 운동 종료' 버튼용 파라미터
) {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.SpaceAround
    ) {
        Text(text = exerciseName, fontSize = 22.sp, textAlign = TextAlign.Center)
        Text(text = count.toString(), fontSize = 72.sp, fontWeight = FontWeight.Bold)
        Column {
            // --- 8. '세트 종료' 버튼으로 기능을 변경합니다. ---
            Button(
                onClick = onSetCompleteClick,
                modifier = Modifier.fillMaxWidth()
            ) {
                Text("세트 종료 (저장)")
            }
            Spacer(modifier = Modifier.height(8.dp))
            Button(
                onClick = onEndWorkoutClick,
                colors = ButtonDefaults.buttonColors(backgroundColor = MaterialTheme.colors.error),
                modifier = Modifier.fillMaxWidth()
            ) {
                Text("전체 운동 종료")
            }
        }
    }
}

// --- 9. '오늘의 운동 기록'을 표시할 화면을 완전히 새로 만듭니다. ---
@Composable
fun TodayWorkoutScreen(sets: List<WorkoutSet>) {
    ScalingLazyColumn(
        modifier = Modifier.fillMaxSize(),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.spacedBy(8.dp)
    ) {
        item {
            Text(
                text = "오늘의 운동 기록",
                style = MaterialTheme.typography.title1,
                modifier = Modifier.padding(bottom = 16.dp)
            )
        }
        if (sets.isEmpty()) {
            item {
                Text(
                    text = "아직 저장된 기록이 없습니다.",
                    modifier = Modifier.padding(top = 24.dp)
                )
            }
        } else {
            items(sets) { set ->
                val timeFormat = SimpleDateFormat("HH:mm:ss", Locale.getDefault())
                val timeString = timeFormat.format(Date(set.timestamp))

                Row(
                    modifier = Modifier.fillMaxWidth(),
                    horizontalArrangement = Arrangement.SpaceBetween,
                    verticalAlignment = Alignment.CenterVertically
                ) {
                    Column(modifier = Modifier.weight(1f)) {
                        Text(text = set.exerciseName, fontWeight = FontWeight.Bold)
                        Text(text = timeString, fontSize = 12.sp, color = Color.Gray)
                    }
                    Text(text = "${set.reps} 회", fontSize = 20.sp)
                }
            }
        }
    }
}


@Composable
fun ExerciseSelectionScreen(onExerciseSelected: (String) -> Unit) {
    ScalingLazyColumn(
        modifier = Modifier.fillMaxSize(),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.spacedBy(8.dp), // 버튼 사이 간격을 자동으로 조절
        contentPadding = PaddingValues(vertical = 16.dp)
    ) {
        item { Text(text = "수집할 운동 선택", modifier = Modifier.padding(bottom = 8.dp)) }

        // --- 👇👇 여기에 버튼들을 추가합니다 👇👇 ---
        item { Button(onClick = { onExerciseSelected(ExerciseType.SQUAT) }) { Text("스쿼트") } }
        item { Button(onClick = { onExerciseSelected(ExerciseType.OVERHEAD_PRESS) }) { Text("오버헤드 프레스") } }
        item { Button(onClick = { onExerciseSelected(ExerciseType.PUSH_UP) }) { Text("푸시업") } }
        item { Button(onClick = { onExerciseSelected(ExerciseType.SIDE_LATERAL_RAISE) }) { Text("사이드 레터럴 레이즈") } }
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