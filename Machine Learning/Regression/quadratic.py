from line import *
fp2, residuals, rank, sv, rcond = sp.polyfit(x, y, 2, full = True)
print("\nQuadratic:")
f2 = sp.poly1d(fp2)
print("Model: %s" % fp2)
print("Error: %s" % error(f2, x, y))
plt.plot(fx, f2(fx), "#ff3344", linewidth = 2)
if __name__ == "__main__":
	plt.legend(["d = %i" % f1.order, "d = %i" % f2.order], loc = "upper left")
	plt.show()