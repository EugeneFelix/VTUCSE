import numpy as np
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn import metrics
from sklearn.datasets import load_iris

iris = load_iris()
X = pd.DataFrame(iris.data, columns=iris.feature_names)
y = pd.Series(iris.target, name='Class')

Xtrain, Xtest, ytrain, ytest = train_test_split(X, y, test_size=0.10, random_state=42)
classifier = KNeighborsClassifier(n_neighbors=5).fit(Xtrain, ytrain)
ypred = classifier.predict(Xtest)

i = 0
print("-" * 40)
print('%-25s %-25s %-25s' % ('Original Label', 'Predicted Label', 'Correct/Wrong'))
print("-" * 40)
for label in ytest:
	print('%-25s %-25s' % (label, ypred[i]), end="")
	if label == ypred[i]:
		print(' %-25s' % ('Correct'))
	else:
		print(' %-25s' % ('Wrong'))
	i = i + 1
print("-" * 40)
print("\nConfusion Matrix:\n", metrics.confusion_matrix(ytest, ypred))
print("-" * 40)
print("\nClassification Report:\n", metrics.classification_report(ytest, ypred))
print("-" * 40)
print('Accuracy of the classifier is %0.2f' % metrics.accuracy_score(ytest, ypred))
print("-" * 40)