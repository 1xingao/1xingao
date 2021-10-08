# -*- coding: utf-8 -*-
import numpy as np
from PIL import Image

#numpy的练习程序
im = Image.open("1xingao/assist/keli.jpg")

mp = np.array(im)
mp_0 = np.array([1, 2, 4])
#生成数组,一个列表代表一维
print(mp.shape)

mp_1 = np.arange(0, 10, 2, dtype=np.int8)

#arange函数可指定起始，结束，步长，类型
#同类型的还有linspace函数它将步长参数换位所指定的数组元素个数
print("mp_1",mp_1)

mp_3 = np.eye(2, 2)
# np.eye(n, m)定义一个二维单位矩阵。i=j（行索引和列索引相等）的元素为 1，其余为 0
print("mp_3:",mp_3) 
#numpy所创建的数组默认类型为double

mp_4 = np.diag([1, 2, 4])
#numpy.diag可以定义一个具有沿对角线给定值的方形二维数组
print("mp_4:",mp_4)  #还可以将二维数组的对角线组成一个一维数组
#在numpy中可以直接对array中的元素进行加减乘除，乘方，使用@则为矩阵乘积也可以使用dot函数
#dot函数用法：c = a.dot(b)
#可以直接使用判断符号（数组a<10）返回另一个array包含每个数据的布尔值
mp_5 = np.array([1,2,3,4,5])
mp_5 *=2 #这样会直接操作原来的数组
# a = np.ones(3, dtype=np.int32)
print("mp_5:",mp_5.max())#类似函数还有min，sum，其中有一个axis参数作用于括号内，
#作用时指定某一特定轴进行运算，抽从右往左计数0开始
#r("numpy_1.png")具体演示位于此图片
mp_6 = np.zeros((3,3))
print("mp_6:",mp_6)
#索引
mp_7 = np.array([[1,2,3,4],[2,3,4,5],[4,5,6,7]])
print("mp_7:",mp_7[2,3])
print(mp_7[0:2,1])
print(mp_7[0:3,0:3])
#存在冒号的时候会进行指定轴的索引，从后往前一次代表0，1，2轴
print(mp_7[  : ,  : ]) #打印所有数组中的数字或者使用...代表所有数字
#print(mp_7[...])等效于mp_7[:,:]
#对多维数组进行 迭代（Iterating） 是相对于第一个轴完成的：\
b = np.array([[0,1,2,3],[4,5,6,7],[7,8,9,0]])
for row in b:
    print(row)
    #此操作会将array数组转化为普通的多维数组
for i in b.flat:#该属性是数组每个元素的迭代器
    print(i)

#形状操作
mp_8 = np.array([1,2,3,4,5,6,7,8,9])
#mp_8.reshape(3,3)
mp_8.ravel()#此函数可以将数组转化为C风格数组
print(mp_8)
mp_9 = mp_8.reshape((3,3))#reshape函数会返回一个新的数组而不是修改原数组
print(mp_9)#resize函数就可以直接修改原来的数组
#如果再reshape函数里面指定第二个值为-1则会自动计算其他的size大小
#数组堆叠
mp_10 = np.array([[1,2],[3,4]])
mp_11 = np.array([[5,6],[7,8]])
mp_12 = np.vstack((mp_10,mp_11))#竖向拼接
mp_13 = np.hstack((mp_10,mp_11))#横向拼接
print("mp_12:",mp_12,"mp_13:",mp_13)

#拆分
mp_14= np.floor(10*np.random.random((2,12)))
print("mp_14:",mp_14)
mp_15 = np.hsplit(mp_14,3)
mp_16 = np.hsplit(mp_14,(3,4))
print("mp_15:",mp_15,"mp_16:",mp_16)
#hsplit函数为延数组水平轴拆分
#vsplit函数为垂直轴拆分，另有array_split函数指定轴拆分

#拷贝和视图
mp_17= np.array([1,2,3,4,5,6,7])
mp_18  = mp_17.view()
#此方法创建一个数据i相同的新数组对象




