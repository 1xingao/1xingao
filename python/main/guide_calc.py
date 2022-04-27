from ctypes import set_last_error
import math
#获取所输入的度分秒转化为纯度
def getradian(a,b,c):
    sum = 0
    sum+=(b/60)
    sum+=(c/3600)
    sum+=a
    return sum
#计算新的坐标
def getnewcoordinate(n,s):#x,y为经纬度，s为距离
    new_x = s*math.cos(math.radians(n))
    new_y = s*math.sin(math.radians(n))
    return new_x,new_y
a_list = [113,136,78,238,213,94,146,161,87,198]
b_list = [32,0,4,37,19,43,41,11,33,36]
c_list = [53,25,36,22,41,44,50,2,54,44]
s_list = [67.609,58.217,43.933,30.849,27.825,40.045,43.603,43.219,70.626,45.431]
# x = 92362.8
# y = 50227.313
# res_list = []
direction = math.atan((50227.313-50196.672)/(92362.8-92359.397))    #计算方向
direction = math.degrees(direction)#转化为角度
# print(direction)
# for a,b,c,s in zip(a_list,b_list,c_list,s_list):
#     new_x,new_y = getnewcoordinate(a,b,c,x,y,s,direction)
#     x = new_x
#     y = new_y
#     direction =  (getradian(a,b,c)+direction-180)*math.pi/180
#     res_list.append([new_x,new_y])
# print(res_list)
# for i in res_list:
#     sum = 0
#     sum+=i[1]
# # print(sum)
#计算距离
def getdistance(x1,y1,x2,y2):
    return math.sqrt((x1-x2)**2+(y1-y2)**2)
#计算角度闭合差
print(math.sin(60))
print(53+25+37+22+19+44+50+2+54+44+54)
print(32+4+37+19+43+41+11+33+36+37)
print(113+136+78+238+213+94+146+161+87+198+151)
print(getradian(1615,293,404))
#计算三个数的平均值
def getaverage(a,b,c):
    return (a+b+c)/3
# print(getaverage(0.969,0.970))
print(67.609+58.217+43.933+30.849+27.825+40.045+43.603+43.219+70.626+45.431)
print(12*pow(11,1/2))
print(64.581+51.972-27.471+10.51+22.292-21.238-39.624-42.994-4.211-17.043)
for ii in s_list:
    print(-0.177*(ii/471.357),"&&&&&---------&&&&",-0.2539*(ii/471.357))
# x_list = []
# y_list = []
# change_x = []
# change_y = []
# res = []
# for i in range(len(x_list)):
#     res.append([x_list[i]+change_x[i],y_list[i]+change_y[i]])
# print(20.006-26.231-34.285-29.003-16.652-33.949-18.199-4.407+70.5+44.118)
# print(getnewcoordinate(getradian(12,42),67.609))
# print()
print(getnewcoordinate(getradian(272,5,35),59.282))