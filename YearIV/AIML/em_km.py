from sklearn.cluster import KMeans
from sklearn.mixture import GaussianMixture
import sklearn.metrics as metrics
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris

iris = load_iris()
X, y = iris.data[:, :2], iris.target

print (X)

plt.figure(figsize=(14, 7))
colormap = np.array(['red', 'lime', 'black'])

# REAL PLOT
plt.subplot(1, 3, 1)
plt.title('Real')
plt.scatter(X[:, 0], X[:, 1], c=colormap[y])

# K-PLOT
kmeans_model = KMeans(n_clusters=3, random_state=0).fit(X)
plt.subplot(1, 3, 2)
plt.title('KMeans')
plt.scatter(X[:, 0], X[:, 1], c=colormap[kmeans_model.labels_])

print('K-Mean Accuracy: ', metrics.accuracy_score(y, kmeans_model.labels_))
print('Confusion Matrix (K-Mean):\n', metrics.confusion_matrix(y, kmeans_model.labels_))

# GMM PLOT
gmm_model = GaussianMixture(n_components=3, random_state=0).fit(X)
y_cluster_gmm = gmm_model.predict(X)
plt.subplot(1, 3, 3)
plt.title('GMM Classification')
plt.scatter(X[:, 0], X[:, 1], c=colormap[y_cluster_gmm])

print('EM Accuracy: ', metrics.accuracy_score(y, y_cluster_gmm))
print('Confusion Matrix (EM):\n', metrics.confusion_matrix(y, y_cluster_gmm))

plt.show()