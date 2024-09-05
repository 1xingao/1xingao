import numpy as np

class LogisticRegression:
    def __init__(self, learning_rate=0.01, num_iterations=10000):
        self.learning_rate = learning_rate
        self.num_iterations = num_iterations
        self.weights = None
        self.bias = None

    def sigmoid(self, z):
        return 1 / (1 + np.exp(-z))

    def fit(self, X, y):
        m, n = X.shape
        self.weights = np.zeros(n)
        self.bias = 0

        for _ in range(self.num_iterations):
            # Forward propagation
            linear_model = np.dot(X, self.weights) + self.bias
            y_pred = self.sigmoid(linear_model)

            # Backward propagation
            dw = (1/m) * np.dot(X.T, (y_pred - y))
            db = (1/m) * np.sum(y_pred - y)

            # Update parameters
            self.weights -= self.learning_rate * dw
            self.bias -= self.learning_rate * db

    def predict(self, X):
        linear_model = np.dot(X, self.weights) + self.bias
        y_pred = self.sigmoid(linear_model)
        return y_pred >= 0.5

def one_vs_other_logistic_regression(X_train, y_train, num_classes):
    models = []

    for i in range(num_classes):
        # Create a binary classifier for class i vs. other classes
        binary_y_train = (y_train == i).astype(int)
        model = LogisticRegression()
        model.fit(X_train, binary_y_train)
        models.append(model)

    return models

def predict_ovo(X_test, models):
    num_classes = len(models)
    num_samples = X_test.shape[0]
    predictions = np.zeros((num_samples, num_classes))

    for i, model in enumerate(models):
        predictions[:, i] = model.predict(X_test).astype(int)

    # Determine the final class based on the classifiers' outputs
    final_predictions = np.argmax(predictions, axis=1)

    return final_predictions

# Example usage:
# Assuming you have X_train, y_train, X_test already defined
num_classes = 4
models = one_vs_other_logistic_regression(X_train, y_train, num_classes)
y_pred = predict_ovo(X_test, models)
