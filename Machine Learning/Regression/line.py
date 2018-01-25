from data import *
from error import error
# fp1 is value of parameters
# residuals is error of approximation
print("Line:")
fp1, residuals, rank, sv, rcond = sp.polyfit(x, y, 1, full = True)
print("Model parameters: %s" % fp1)
# Model is:
f1 = sp.poly1d(fp1)
print("Model: %s" % f1)
# Error in model 
print("Residual: %s" % residuals)
# Checking the error ourselves
print("Error: %s" % error(f1, x, y))
# Plot
fx = sp.linspace(0, x[-1], 1000) # Generate x values
plt.plot(fx, f1(fx), "#33ff44", linewidth = 2)
if __name__ == "__main__":
	plt.legend(["d = %i" % f1.order], loc = "upper left")
	plt.show()