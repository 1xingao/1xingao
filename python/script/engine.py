'''
Author: xinao_seven_
Date: 2023-06-19 22:10:26
LastEditTime: 2023-06-19 22:19:42
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \1xingao\python\script\engine.py

'''
new = []
ano = []
path  = "专业英语.md"
with open(path,"r", encoding='utf-8-sig') as f:
    for i in f.readlines():
        res = i.split(" ")
        temp = ""
        for j in range(len(res)-1):
            temp+=res[j]+" "
        new.append(temp)
        ano.append(res[-1])
with open("new.md","w", encoding='utf-8-sig') as f:
    for i in range(len(new)):
        f.writelines(new[i])
        f.writelines("\n")
with open("ano.md","w", encoding='utf-8-sig') as f:
    for i in range(len(new)):
        f.writelines(ano[i])
        f.writelines("\n")