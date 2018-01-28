from data import *
# Week 3.5 is taken as inflection point
inflection = int(3.5 * 7 * 24)
xa = x[:inflection]
ya = y[:inflection]
xb = x[inflection:]
yb = y[inflection:]

fa = sp.poly1d(sp.polyfit(xa, ya, 1))
fb = sp.poly1d(sp.polyfit(xb, yb, 1))
fb2 = sp.poly1d(sp.polyfit(xb, yb, 2))
fb10 = sp.poly1d(sp.polyfit(xb, yb, 10))

fa_error = error(fa, xa, ya)
fb_error = error(fb, xb, yb)

print("Error inflection = %f" % (fa_error + fb_error))

fxa = sp.linspace(0, xa[-1] + 100, 1000) # Generate x values
fxb = sp.linspace(inflection - 50, xb[-1], 1000) # Generate x values

plt.plot(fxa, fb10(fxa), "#33ff44", linewidth = 2)
# plt.plot(fxb, fb(fxb), "#ff3344", linewidth = 2, linestyle = "dashed")

if __name__ == "__main__":
	legendArray = [1, 1]
	plt.legend(["d = %i" % fa.order, "d = %i" % fb.order], loc = "upper left")
	plt.show()