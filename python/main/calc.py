
import math
from tokenize import Double

#角度转化为弧度
def dmsToRad(dms:Double):
    temp_dms = abs(dms)
    du = int(temp_dms)
    fn = (temp_dms-du)*100
    fn_tem = int(fn)
    m = (fn-fn_tem)*100
    alldi = du+fn/60+m/3600
    return math.radians(alldi)

#弧度转化为角度
def radToDms(rad:Double):
    rad = math.degrees(rad)
    du  = int(rad)
    fn = (rad-du)*60
    ms_ = int(fn)
    ms = (ms_ - fn) *60
    return du+fn/100+ms/10000

#坐标正算
def zuoBiao(x:Double,y:Double,s,alpha):
    x = x+s*math.cos(alpha)
    y = y+s*math.sin(alpha)
    return x,y

#坐标反算
def fanBiao(x:Double,y:Double,x2,y2):
    s = math.sqrt((x-x2)**2+(y-y2)**2)
    alpha = math.atan2(y-y2,x-x2)
    if alpha<0:
        return alpha+2*math.pi
    return s,alpha

print(dmsToRad(11.2233))
print(radToDms(3.14))
print(zuoBiao(1,2,10,0.5))
print(fanBiao(9.7,6.7,1,2))
# class Station:
    
#     def __init__(self,hsd,qsd,leng,hight) -> None:
#         self.hsd_name = hsd
#         self.qsd_name =qsd
#         self.lenth = leng
#         self.hight = hight
    
# class Point:
#     def __init__(self,name,height) -> None:
#         self.name = name
#         self.height = height
#         self.flag = False

#     def __init__(self,name,height,flag) -> None:
#         self.name = name
#         self.height = height
#         #flag属性为false时候事未知点
#         self.flag = flag

# #463085927
# filename = ""
# list_point= []
# with open(filename,"r") as fp:
#     while(fp.readlines()!=NULL):
#         listy = fp.readlines().split(",")
#         p1 = Point(listy[0],listy[1])
#         list_point.append(p1)
#     for line in fp.readlines():
#         li_list = line.split(",")
#         s1 = Station()
