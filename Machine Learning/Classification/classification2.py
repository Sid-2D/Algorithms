from data import *

labels = [data['target_names'][target[w]] for w in xrange(len(target))]
is_setosa = (target == 0)
print is_setosa
features = features[~is_setosa]
# labels = labels[~is_setosa]
virginica = (labels == 'virginica')

print(features[:,1])
best_acc = -1.0
for fi in xrange(features.shape[1]):
	# Generate all possible thresholds for this feature
	thresh = features[:, fi].copy()
	thresh.sort()
	# Test all possible thresholds
	for t in thresh:
		prediction = (features[:, fi] > t)
		accuracy = (prediction == virginica).mean()
		if accuracy > best_acc:
			best_acc = accuracy
			best_fi	= fi
			best_t = t

print(best_fi)
print(best_acc)
print(best_t)