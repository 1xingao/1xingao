import numpy as np
# k = np.array([1,3,-2])

# x = np.array([[3,0,-1],[0,2,1/2],[-1,1/2,1]])
# l = np.array([[1,1,1]])
# f1 = np.array([2,0,-1])
# f2 = np.array([[5,-1]])
# ll = np.array([[3,0,-1],[0,4,1],[-1,1,2]])
# x = np.matrix(x)
# print(x)
# print(0,x.I)
# print(1,np.linalg.inv(x))
# ar = np.diag([1/2,1/2,1/3])
# ar = np.matrix(ar)
# print(ar.I)
# a = np.array([1,1,1])
# a = np.matrix(a)
# print(a.T)
# print(a@ar.I@a.T)
# print(1.335+1.055-2.396)
# print(ar.I@a.T)
# qc = np.diag([9,4,1])
# print(qc@a.T)
# print(f1@ll@f1.T))
a = np.zeros((4,7))
a[0][0] =a[0][4]= a[1][4]=a[1][5]=a[2][2] =a[3][0] =  1
a[0][1] = a[1][6] = a[2][5] = a[2][3] = a[3][2] = -1
w = np.array([7,7,3,-4])
p = np.diag([1,1,1/2,1/2,1,1,1/2])
a =np.matrix(a)
p = np.matrix(p)
w = np.matrix(w)
print(a@p.I@a.T)
naa = a@p.I@a.T
k = -naa.I@w.T
v= p.I@a.T@k
print(v)
