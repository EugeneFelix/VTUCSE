import numpy as np

X = np.array([[2, 9],
			  [1, 5],
			  [3, 6]], dtype=float)
y = np.array([[92],
			  [86],
			  [89]], dtype=float)
# Normalise data
X, y = X / np.amax(X, axis=0), y / 100

def sigmoid(x):
	return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
	return x * (1 - x)

epochs, lr = 5, 0.1
wh, bh = np.random.uniform(size=(2,3)), np.random.uniform(size=(1, 3))
wout, bout = np.random.uniform(size=(3,1)), np.random.uniform(size=(1, 1))

for _ in range(epochs):
	# Forward pass
	h_layer_in = np.dot(X, wh) + bh
	h_layer_act = sigmoid(h_layer_in)
	o_layer_in = np.dot(h_layer_act, wout) + bout
	output = sigmoid(o_layer_in)

	# d = delta, d = error × gradient
	# gradient is from sig_derivative
	EO, out_grad = y - output, sigmoid_derivative(output)
	d_output = EO * out_grad
	EH, hidden_grad = d_output.dot(wout.T), sigmoid_derivative(h_layer_act)
	d_hidden = EH * hidden_grad
	
	# Gradient (steepest increase) descent
	wout += h_layer_act.T.dot(d_output) * lr
	wh += X.T.dot(d_hidden) * lr

	print("-----------Epoch-----------\nInput:\n", X, "\nActual Output:\n", y, "\nPredicted Output:\n", output)

print("Input:\n", X, "\nActual Output:\n", y, "\nFinal Predicted Output:\n", output)