'''
Author: xinao_seven_
Date: 2022-12-01 18:50:47
LastEditTime: 2022-12-01 20:09:09
LastEditors: xinao_seven_
Description: latex transform
Encoding: utf8
FilePath: \\1xingao\\python\\script\\latex.py

'''

import latexify

import math

@latexify.with_latex
def func(x,y,z_1):
    
    return math.sin(x)/y/ + z_1

print(func)