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

#5.4.44
# a = np.zeros((4,7))
# a[0][0] =a[0][4]= a[1][4]=a[1][5]=a[2][2] =a[3][0] =  1
# a[0][1] = a[1][6] = a[2][5] = a[2][3] = a[3][2] = -1
# w = np.array([7,7,3,-4])
# p = np.diag([1,1,1/2,1/2,1,1,1/2])
# a =np.matrix(a)
# p = np.matrix(p)
# w = np.matrix(w)
# print(a@p.I@a.T)
# naa = a@p.I@a.T
# k = -naa.I@w.T
# v= p.I@a.T@k
# print("v:",v)
# h = np.array([10.356,15.000,20.360,14.501,4.651,5.856,10.500])
# h = np.matrix(h)
# print(v/1000+h.T)
# print((v.T@p@v)/4**0.5)

#6.1.09
# a = np.zeros((2,3))
# a[0][0] = a[1][1] = a[1][0] = a[1][2] = 1
# b = np.array([1,0])
# w = np.array([0,-6])
# p = np.diag([1,1/2,1])
# a = np.matrix(a)
# _b = np.matrix(b)
# _w = np.matrix(w)
# p = np.matrix(p)
# naa = a@p.I@a.T
# b= _b.T
# w = _w.T
# nbb = b.T@naa.I@b
# x = -nbb.I@b.T@naa.I@w
# print(a)
# print(b)
# print(w)
# print(x)
# k = -naa.I@(b@x+w)
# print(k)
# v = p.I@a.T@k
# print(v)

#6.3.23
a = np.zeros((4,4))
a[0][0] = a[1][0] = a[1][2] = a[2][0] = a[3][2] =1
a[2][1] = a[3][3] = -1
a = np.matrix(a)
_b = np.array([-1,0,0,0])
_w = np.array([0,3,-2,2])
p = np.diag([1,1,1,1])
_b = np.matrix(_b)
_w = np.matrix(_w)
b = _b.T
w = _w.T
p = np.matrix(p)
naa = a@p.I@a.T
nbb = b.T@naa.I@b
x = -nbb.I@b.T@naa.I@w
print(x)
k = -naa.I@(b@x+w)
print(k)
v = p.I@a.T@k
print(v)