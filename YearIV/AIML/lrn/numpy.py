import numpy as np

'''
axis 0 = columns
axis 1 = rows
'''
a = np.array([[5,7], [1,2]])
print(a[1])
print("Shape is", a.shape)
print("Amax is ", np.amax(a, axis=0))

a = np.arange(1, 10, 1)
print(a)

'''
uniform random: [a, b), half open range
				size: (int, int, int, ...)
'''
a = np.random.uniform(10, 21, size=(2,2))
print(a)