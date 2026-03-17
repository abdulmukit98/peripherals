import numpy as np
from sklearn.tree import DecisionTreeClassifier
from micromlgen import port

# dataset
X = np.array([
    [0],
    [1023]
])

y = np.array([
    0, 1    
])

model = DecisionTreeClassifier()
model.fit(X,y)

#########################################

c_code = port(model)

with open("model.h", "w") as f:
    f.write(c_code)

print("model exported to model.h")
