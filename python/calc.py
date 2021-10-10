import math
#最小二乘法计算普朗克常数
#更改data_u里面的数据为你自己的截至电压
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
        
    return temp/5.0

v = int(ba_defang(data_v)*1000)/1000
u = int(ba_defang(data_u)*1000)/1000
dela = int(cac(data_v,data_u)*1000)/1000
dea2 = int(ba_fangping(data_v)*100)/100
k = (ba_defang(data_v)*ba_defang(data_u) - cac(data_v,data_u) ) /( math.pow(ba_defang(data_v),2) - ba_fangping(data_v))
print("理论斜率：",k)
print("v平均：",v)
print("Us平均：",u)
print("乘积平均：",dela)
print("先^2平均：",dea2)
h0 = 6.626
#kd = (ba_defang(data_v)*ba_defang(data_u) - cac(data_v,data_u) ) /( math.pow(ba_defang(data_v),2) - ba_fangping(data_v))
kd = (v*u - dela )/(math.pow(v,2) - dea2)
print("实际计算k：",(int(kd*1000)/1000))
h1 = (int(kd*1000)/1000)*e

h1 = h1*-10
h1 = (int(h1*1000))/1000

print("绝对误差：",abs(h1-h0))
print("相对误差：",(int((abs(h1-h0)/h0)*1000))/10,"%")