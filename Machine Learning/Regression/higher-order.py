from quadratic import *
# Order 3
print("\nOrder 3:")
fp3 = sp.polyfit(x, y, 3)
f3 = sp.poly1d(fp3)
print("Model: %s" % fp3)
plt.plot(fx, f3(fx), "#bada55", linewidth = 2)

# Order 10
print("\nOrder 10:") 
fp10 = sp.polyfit(x, y, 10)
f10 = sp.poly1d(fp10)
print("Model: %s" % fp10)
plt.plot(fx, f10(fx), "#333333", linewidth = 2)

# Order 100
print("\nOrder 100:") 
fp100 = sp.polyfit(x, y, 100)
f100 = sp.poly1d(fp100)
plt.plot(fx, f100(fx), "#999999", linewidth = 2)

print("Error 3:   %s" % error(f3, x, y))
print("Error 10:  %s" % error(f10, x, y))
print("Error 100: %s" % error(f100, x, y))

if __name__ == "__main__":
	legendArray = [1, 2, 3, 10, 100]
	plt.legend(["d = %i" % legendArray[w] for w in range(len(legendArray))], loc = "upper left")
	plt.show()	