package com.example.geunhwang.presentation

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
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

// --- 👇👇 여기에 모든 정의를 다시 추가합니다 👇👇 ---
// 이 파일 및 다른 파일에서 함께 사용할 약속들입니다.
object ExerciseType {
    const val DUMBBELL_CURL = "Dumbbell Curl"
    const val SQUAT = "Squat"
}
enum class DumbbellCurlState { READY, LIFTING, LOWERING }
enum class SquatState { READY, DESCENDING, ASCENDING }
// --- 👆👆 여기까지 👆👆 ---


class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            val viewModel: MainViewModel = viewModel()

            GeunHwangTheme {
                WearAppNavigation(
                    repCountFlow = viewModel.repCount,
                    onExerciseSelected = viewModel::onExerciseSelected,
                    onWorkoutEnd = viewModel::onWorkoutEnd
                )
            }
        }
    }
}


// --- 아래 UI 코드는 변경 없습니다. ---
@Composable
fun WearAppNavigation(
    repCountFlow: StateFlow<Int>,
    onExerciseSelected: (String) -> Unit,
    onWorkoutEnd: () -> Unit
) {
    val navController = rememberSwipeDismissableNavController()

    SwipeDismissableNavHost(
        navController = navController,
        startDestination = "main_screen"
    ) {
        composable("main_screen") {
            MainScreen(
                onDumbbellCurlClick = {
                    onExerciseSelected(ExerciseType.DUMBBELL_CURL)
                    navController.navigate("counter_screen/${ExerciseType.DUMBBELL_CURL}")
                },
                onSquatClick = {
                    onExerciseSelected(ExerciseType.SQUAT)
                    navController.navigate("counter_screen/${ExerciseType.SQUAT}")
                }
            )
        }

        composable("counter_screen/{exerciseName}") { backStackEntry ->
            val exerciseName = backStackEntry.arguments?.getString("exerciseName") ?: "운동"
            val repCount by repCountFlow.collectAsState()

            CounterScreen(
                exerciseName = exerciseName,
                count = repCount,
                onEndWorkoutClick = {
                    onWorkoutEnd()
                    navController.popBackStack()
                }
            )
        }
    }
}

@Composable
fun MainScreen(onDumbbellCurlClick: () -> Unit, onSquatClick: () -> Unit) {
    Column(
        modifier = Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Button(onClick = onDumbbellCurlClick) {
            Text("덤벨 컬")
        }
        Spacer(modifier = Modifier.height(16.dp))
        Button(onClick = onSquatClick) {
            Text("스쿼트")
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
