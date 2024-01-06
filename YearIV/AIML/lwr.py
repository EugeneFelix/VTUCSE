import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def gaussian_kernel(point, x_matrix, bandwidth):
	m, n = np.shape(x_matrix)
	weights = np.mat(np.eye(m))
	for j in range(m):
		diff = point - x_matrix[j]
		weights[j, j] = np.exp(diff * diff.T / (-2.0 * bandwidth**2))
	return weights

def local_weight(point, x_matrix, y_matrix, bandwidth):
	weight_matrix = gaussian_kernel(point, x_matrix, bandwidth)
	local_weights = (x_matrix.T * (weight_matrix * x_matrix)).I * (x_matrix.T * (weight_matrix * y_matrix.T))
	return local_weights

def local_weight_regression(x_matrix, y_matrix, bandwidth):
	m, n = np.shape(x_matrix)
	y_pred = np.zeros(m)
	for i in range(m):
		y_pred[i] = x_matrix[i] * local_weight(x_matrix[i], x_matrix, y_matrix, bandwidth)
	return y_pred

# Load data points
tips_data = pd.read_csv('../data/tips.csv')
total_bill = np.array(tips_data.total_bill)
tip_amount = np.array(tips_data.tip)

# Prepare and add a column of 1's to total_bill
total_bill_matrix = np.mat(total_bill)
tip_matrix = np.mat(tip_amount)

num_samples = np.shape(total_bill_matrix)[1]
ones_column = np.mat(np.ones(num_samples))
X_matrix = np.hstack((ones_column.T, total_bill_matrix.T))

# Perform locally weighted regression
predicted_tip = local_weight_regression(X_matrix, tip_matrix, 0.5)

# Sort data for plotting
sort_index = X_matrix[:, 1].argsort(0)
sorted_data = X_matrix[sort_index][:, 0]

# Plot the results
fig, ax = plt.subplots()
ax.scatter(total_bill, tip_amount, color='green')
ax.plot(sorted_data[:, 1], predicted_tip[sort_index], color='red', linewidth=5)
plt.xlabel('Total bill')
plt.ylabel('Tip')
plt.show()