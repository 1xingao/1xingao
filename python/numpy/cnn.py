'''
Author: xinao_seven_
Date: 2023-07-28 11:04:35
LastEditTime: 2023-07-28 11:17:01
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \1xingao\python\numpy\cnn.py

'''
import numpy as np

class FourLayerNeuralNetwork:
    def __init__(self, input_dim, hidden_dim, output_dim):
        self.input_dim = input_dim
        self.hidden_dim = hidden_dim
        self.output_dim = output_dim

        # 初始化权重和偏置
        self.W1 = np.random.randn(self.input_dim, self.hidden_dim)
        self.b1 = np.zeros((1, self.hidden_dim))
        self.W2 = np.random.randn(self.hidden_dim, self.hidden_dim)
        self.b2 = np.zeros((1, self.hidden_dim))
        self.W3 = np.random.randn(self.hidden_dim, self.hidden_dim)
        self.b3 = np.zeros((1, self.hidden_dim))
        self.W4 = np.random.randn(self.hidden_dim, self.output_dim)
        self.b4 = np.zeros((1, self.output_dim))

    def forward(self, X):
        # 前向传播
        self.z1 = np.dot(X, self.W1) + self.b1
        self.a1 = self.relu(self.z1)
        self.z2 = np.dot(self.a1, self.W2) + self.b2
        self.a2 = self.relu(self.z2)
        self.z3 = np.dot(self.a2, self.W3) + self.b3
        self.a3 = self.relu(self.z3)
        self.z4 = np.dot(self.a3, self.W4) + self.b4
        self.y_hat = self.softmax(self.z4)

    def relu(self, x):
        return np.maximum(0, x)

    def softmax(self, x):
        exp_x = np.exp(x - np.max(x, axis=1, keepdims=True))
        return exp_x / np.sum(exp_x, axis=1, keepdims=True)

    def predict(self, X):
        self.forward(X)
        return np.argmax(self.y_hat, axis=1)

    def train(self, X, y, learning_rate=0.01, epochs=1000):
        for epoch in range(epochs):
            # 前向传播
            self.forward(X)

            # 计算损失
            loss = -np.sum(np.log(self.y_hat[range(len(y)), y])) / len(y)

            # 计算梯度
            dL_dz4 = self.y_hat
            dL_dz4[range(len(y)), y] -= 1
            dL_dz4 /= len(y)

            dL_da3 = np.dot(dL_dz4, self.W4.T)
            dL_dz3 = dL_da3 * (self.z3 > 0)

            dL_da2 = np.dot(dL_dz3, self.W3.T)
            dL_dz2 = dL_da2 * (self.z2 > 0)

            dL_da1 = np.dot(dL_dz2, self.W2.T)
            dL_dz1 = dL_da1 * (self.z1 > 0)

            # 更新权重和偏置
            self.W4 -= learning_rate * np.dot(self.a3.T, dL_dz4)
            self.b4 -= learning_rate * np.sum(dL_dz4, axis=0, keepdims=True)

            self.W3 -= learning_rate * np.dot(self.a2.T, dL_dz3)
            self.b3 -= learning_rate * np.sum(dL_dz3, axis=0, keepdims=True)

            self.W2 -= learning_rate * np.dot(self.a1.T, dL_dz2)
            self.b2 -= learning_rate * np.sum(dL_dz2, axis=0, keepdims=True)

            self.W1 -= learning_rate * np.dot(X.T, dL_dz1)
            self.b1 -= learning_rate * np.sum(dL_dz1, axis=0, keepdims=True)

            if epoch % 100 == 0:
                print(f"Epoch {epoch}, Loss: {loss}")

# 创建一个简单的数据集用于演示
X_train = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y_train = np.array([0, 1, 1, 0])

# 初始化神经网络
input_dim = X_train.shape[1]
hidden_dim = 4
output_dim = 2
nn = FourLayerNeuralNetwork(input_dim, hidden_dim, output_dim)

# 训练神经网络
nn.train(X_train, y_train, learning_rate=0.1, epochs=1000)

# 验证准确率
predictions = nn.predict(X_train)
accuracy = np.mean(predictions == y_train)
print(f"Accuracy: {accuracy * 100:.2f}%")
