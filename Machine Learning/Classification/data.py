from matplotlib import pyplot as plt
from sklearn.datasets import load_iris
import numpy as np

data = load_iris()
features = data['data']
feature_names = data['feature_names']
target = data['target']

# Features: ['sepal length (cm)', 'sepal width (cm)', 'petal length (cm)', 'petal width (cm)']

# Separates three types of flowers based on the row number given in target
for t, marker, color in zip(xrange(3), ">ox", "rgb"):
	print(t, marker, color)

if __name__ == "__main__":
	# sepal length vs sepal width
	for t, marker, color in zip(xrange(3), ">ox", "rgb"):
		plt.scatter(features[target == t, 0], # Select first column of data in features where row number is same as target
					features[target == t, 1],
					marker = marker,
					c = color)
	plt.xlabel("Sepal length (cm)")
	plt.ylabel("Sepal width (cm)")
	plt.show()

	# sepal length vs petal length
	for t, marker, color in zip(xrange(3), ">ox", "rgb"):
		plt.scatter(features[target == t, 0], # Select first column of data in features where row number is same as target
					features[target == t, 2],
					marker = marker,
					c = color)
	plt.xlabel("Sepal length (cm)")
	plt.ylabel("Petal length (cm)")
	plt.show()

	# sepal length vs petal width
	for t, marker, color in zip(xrange(3), ">ox", "rgb"):
		plt.scatter(features[target == t, 0], # Select first column of data in features where row number is same as target
					features[target == t, 3],
					marker = marker,
					c = color)
	plt.xlabel("Sepal length (cm)")
	plt.ylabel("Petal width (cm)")
	plt.show()

	# sepal width vs petal length
	for t, marker, color in zip(xrange(3), ">ox", "rgb"):
		plt.scatter(features[target == t, 1], # Select first column of data in features where row number is same as target
					features[target == t, 2],
					marker = marker,
					c = color)
	plt.xlabel("Sepal width (cm)")
	plt.ylabel("Petal length (cm)")
	plt.show()

	# sepal width vs petal width
	for t, marker, color in zip(xrange(3), ">ox", "rgb"):
		plt.scatter(features[target == t, 1], # Select first column of data in features where row number is same as target
					features[target == t, 3],
					marker = marker,
					c = color)
	plt.xlabel("Sepal width (cm)")
	plt.ylabel("Petal width (cm)")
	plt.show()

	# petal length vs petal width
	for t, marker, color in zip(xrange(3), ">ox", "rgb"):
		plt.scatter(features[target == t, 2], # Select first column of data in features where row number is same as target
					features[target == t, 3],
					marker = marker,
					c = color)
	plt.xlabel("Petal length (cm)")
	plt.ylabel("Petal width (cm)")
	plt.show()