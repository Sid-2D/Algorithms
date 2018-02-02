import numpy as np
import pandas as pd
from sklearn import tree
from IPython.display import Image  
from sklearn.externals.six import StringIO  
import pydotplus

input_file = "link/to/file"
df = pd.read_csv(input_file, header = 0)

boolMap = {'Y': 1, 'N': 0}
df['Hired'] = df['Hired'].map(boolMap)
df['Employed?'] = df['Employed?'].map(boolMap)
df['Top-tier school'] = df['Top-tier school'].map(boolMap)
df['Interned'] = df['Interned'].map(boolMap)
qualMap = {'BS': 0, 'MS': 1, 'PhD': 2}
df['Level of Education'] = df['Level of Education'].map(qualMap)
print df.head()

features = list(df.columns[:6])

y = df["Hired"]
X = df[features]
clf = tree.DecisionTreeClassifier()
X.as_matrix()
print X

clf = clf.fit(X,y)

dot_data = StringIO()  
tree.export_graphviz(clf, out_file=dot_data,  
                         feature_names=features)  
graph = pydotplus.graph_from_dot_data(dot_data.getvalue())  
Image(graph.create_png()) 