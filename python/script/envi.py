'''
Author: xinao_seven_
Date: 2022-08-31 22:38:00
LastEditTime: 2022-11-08 16:01:08
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\script\\envi.py

'''
import shutil
import os
os.system("@echo off")
path = "C:\\Users\\藏起来的十七\\.idl"

try:
    shutil.rmtree(path)
except OSError as e:
    print(e)
else:
    print("The directory is deleted successfully")

input()
