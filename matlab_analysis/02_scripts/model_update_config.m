% =========================================================================
% [ CONFIG FILE ] : model_update_config.m (Version 2.0)
% =========================================================================

function config = model_update_config()
    % --- 설정 (사용자 수정 필요) ---

    % 1. 새로 내보내기 한 모델 파일의 이름을 입력하세요. (예: 'myEnsembleModel_v1.mat')
    config.new_model_file = 'myEnsembleModel_v2.mat'; 

    % 2. 안드로이드 프로젝트의 'cpp' 폴더 절대 경로를 입력하세요.
    config.android_cpp_prediction_path = 'C:\Users\SeokHoLee\StudioProjects\GeunHwang\app\src\main\cpp\prediction';

end