function predicted_class_index = predictExercise_ClassificationKNN(sensorData, train_data_X, train_data_Y, k, class_names)
%#codegen
    features_array = feature_extractor_codegen(sensorData);
    num_train_samples = size(train_data_X, 1);
    distances = zeros(1, num_train_samples);
    for i = 1:num_train_samples
        distances(i) = sqrt(sum((features_array - train_data_X(i, :)).^2));
    end
    [~, sorted_indices] = sort(distances);
    k_nearest_indices = sorted_indices(1:k);
    k_nearest_labels = train_data_Y(k_nearest_indices);
    predicted_label = mode(k_nearest_labels);
    predicted_class_index = find(strcmp(class_names, predicted_label));
end