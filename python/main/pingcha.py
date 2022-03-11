import numpy as np
k = np.array([1,3,-2])

x = np.array([[3,0,-1],[0,2,1/2],[-1,1/2,1]])
l = np.array([[1,1,1]])
f1 = np.array([2,0,-1])
f2 = np.array([[5,-1]])
ll = np.array([[3,0,-1],[0,4,1],[-1,1,2]])
x = np.matrix(x)
print(x)
print(0,x.I)
print(1,np.linalg.inv(x))
# print(f1@ll@f1.T)
