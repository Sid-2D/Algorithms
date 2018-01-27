# Separate iris setosa from other using petal length

from data import *
import pprint

plength = features[:, 2] 
is_setosa = (target == 0)
pp = pprint.PrettyPrinter(indent = 4)

max_setosa = plength[is_setosa].max()
min_non_setosa = plength[~is_setosa].min()
print('Max of setosa: {0}'.format(max_setosa)) 	   # 1.9
print('Min of others: {0}'.format(min_non_setosa)) # 3.0

# pp.pprint(max_setosa)
print(plength)
for i in range(len(plength)):
	if plength[i] <= max_setosa:
		print 'Iris Setosa'
	else:
		print 'Iris Virginica or Iris Versicolor'