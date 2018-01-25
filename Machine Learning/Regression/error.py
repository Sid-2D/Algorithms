# y is desired output vector and f(x) is output from our model
# x and y are vectors from data_plot.py
import scipy as sp
def error(f, x, y):
	return sp.sum((f(x) - y) ** 2)