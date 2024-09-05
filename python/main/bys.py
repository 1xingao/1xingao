'''
Author: xinao_seven_
Date: 2023-07-20 22:50:35
LastEditTime: 2023-07-20 22:50:44
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \1xingao\python\main\bys.py

'''
import numpy as np

class MultinomialNaiveBayes:
    def __init__(self, alpha=1.0):
        self.alpha = alpha
        self.vocab = set()
        self.class_probs = {}
        self.word_probs = {}
        self.classes = set()

    def fit(self, X, y):
        # X: List of text documents (list of lists)
        # y: List of corresponding class labels (list)
        num_docs = len(X)
        num_classes = len(set(y))

        self.classes = set(y)

        # Calculate class probabilities
        for cls in self.classes:
            self.class_probs[cls] = np.log(np.mean(np.array(y) == cls))

        # Build vocabulary
        for doc in X:
            self.vocab.update(doc)

        vocab_size = len(self.vocab)
        word_counts = {cls: np.ones(vocab_size) * self.alpha for cls in self.classes}
        class_counts = {cls: self.alpha * vocab_size for cls in self.classes}

        # Count words for each class
        for i, doc in enumerate(X):
            cls = y[i]
            for word in doc:
                word_idx = list(self.vocab).index(word)
                word_counts[cls][word_idx] += 1
                class_counts[cls] += 1

        # Calculate word probabilities for each class
        for cls in self.classes:
            self.word_probs[cls] = np.log(word_counts[cls] / class_counts[cls])

    def predict(self, X):
        predictions = []
        for doc in X:
            scores = {cls: self.class_probs[cls] for cls in self.classes}
            for word in doc:
                if word in self.vocab:
                    word_idx = list(self.vocab).index(word)
                    for cls in self.classes:
                        scores[cls] += self.word_probs[cls][word_idx]

            pred_cls = max(scores, key=scores.get)
            predictions.append(pred_cls)
        return predictions


# Example data
X_train = [
    ["good", "great", "awesome"],
    ["bad", "horrible", "awful"],
    ["good", "nice"],
    ["bad", "terrible"],
    ["great", "excellent", "perfect"],
    ["nice", "awesome"],
    ["horrible", "terrible", "awful"],
    ["good", "excellent", "perfect"]
]
y_train = ["positive", "negative", "positive", "negative", "positive", "positive", "negative", "positive"]

X_test = [
    ["good", "awesome"],
    ["bad", "awful"],
    ["great", "perfect"],
    ["nice", "excellent"]
]

# Create and train the model
model = MultinomialNaiveBayes()
model.fit(X_train, y_train)

# Make predictions on the test data
predictions = model.predict(X_test)
print(predictions)
