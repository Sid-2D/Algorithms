# Setup data into two arrays
import scipy as sp
import matplotlib.pyplot as plt
from error import error
data = sp.genfromtxt("web_traffic.tsv", delimiter="\t")
x = data[:, 0]
y = data[:, 1]
x = x[~sp.isnan(y)]
y = y[~sp.isnan(y)]
# Setup graph for plotting
plt.scatter(x, y, s=2)
plt.title("Web traffic over last month")
plt.xlabel("Time")
plt.ylabel("Hits/hour")
plt.xticks([w * 7 * 24 for w in range(10)], ['week %i'%w for w in range(10)])
plt.autoscale(tight=True)
x1,x2,y1,y2 = plt.axis()
plt.axis((x1, x2, 0, 10000))
if __name__ == "__main__": 
	plt.grid()
	plt.show()