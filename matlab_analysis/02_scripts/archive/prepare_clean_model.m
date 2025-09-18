% prepare_clean_model.m

% 1. 새로 내보낸 모델 파일을 불러옵니다.
% 'myEnsembleModel.mat'를 본인의 파일 이름으로 바꾸세요.
original_data = load('myEnsembleModel.mat');

% 2. 구조체 안에서 순수한 모델 객체만 추출합니다.
% 'myEnsembleModel.ClassificationEnsemble'를 본인의 변수 구조에 맞게 바꾸세요.
% whos -file myEnsembleModel.mat 명령어로 구조를 확인할 수 있습니다.
actual_model = original_data.myEnsembleModel.ClassificationEnsemble;

% 3. 추출한 모델 객체만을 'cleanModel.mat'라는 이름으로 덮어쓰기 저장합니다.
save('cleanModel.mat', 'actual_model', '-v7.3');

disp('새로운 모델로 "cleanModel.mat" 파일을 성공적으로 덮어썼습니다.');