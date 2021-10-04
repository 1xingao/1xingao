#写各种脚本的文件
#作者：xinao-seven
#用处：数字图像处理结果计算


from numpy import log2
c=0
def clac(n):
    return n/64.0 *log2(n)

data_list = [5,12,16,8,1,7,10,5]
for i in data_list:
    b=clac(i)
    print(b)
    c+=b
print(c)