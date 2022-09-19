'''
Author: xinao_seven_
Date: 2022-09-18 20:50:34
LastEditTime: 2022-09-18 21:00:20
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\numpy\\123.py

'''

data = []
with open("python\\numpy\\data.txt","r") as f:

    
    for i in f.readlines():
        i = i.replace("[","")
        i = i.replace("]","")
        
        data.append(i)



with open("python\\numpy\\data.txt","w") as f1:
    for i in range(len(data)):
        f1.writelines()(str(data[i]))