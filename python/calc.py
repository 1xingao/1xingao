import math
#最小二乘法计算普朗克常数
data_v = [8.216,7.410,6.882,5.492,5.196]
data_u = [-1.892,-1.608,-1.295,-0.748,-0.638]
data_x = [-1.797,-1.250,-1.220,-0.661,-0.556]
data_c = [-1.674,-1.339,-1.092,-0.571,-0.447]
data_t = [-1.837,-1.337,-1.539,-0.755,-0.610]
e = 1.602
#计算平均值
def ba_defang(x):
    temp = 0
    for i in x:
        temp +=i
        
    return temp/5.0
#计算平方的平均值
def ba_fangping(x):
    temp = 0
    for i in x:
        temp += i*i
    return temp / 5.0
#计算乘积的平均值
def cac(x,y):
    temp = 0
    for i,j in zip(x,y):
        temp += i*j
        print("Uv计算：",i,"*",j,"+")
    return temp/5.0

k = (ba_defang(data_v)*ba_defang(data_u) - cac(data_v,data_u) ) /( math.pow(ba_defang(data_v),2) - ba_fangping(data_v))
print("斜率：",k)
print("v平均：",ba_defang(data_v))
print("Us平均：",ba_defang(data_u))
print("乘积平均：",cac(data_v,data_u))
print("先^2平均：",ba_fangping(data_v))
print(e*-0.424)