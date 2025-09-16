function codegen_args = getParameters_ClassificationKNN(model_object, sensor_data_type)
% [OVERVIEW] KNN 모델의 파라미터를 추출하고, codegen을 위한 전체 인자 목록을 생성합니다.

    train_data_X = model_object.X;
    train_data_Y = model_object.Y;
    k = model_object.NumNeighbors;
    class_names = model_object.ClassNames;

    % --- ▼▼▼ [핵심 수정] '메모지'와 '코팅된 카드'를 처음부터 하나의 완벽한 세트로 만듭니다. ▼▼▼
    codegen_args = {sensor_data_type, coder.Constant(train_data_X), coder.Constant(train_data_Y), coder.Constant(k), coder.Constant(class_names)};
end