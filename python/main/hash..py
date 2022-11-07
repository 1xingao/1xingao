'''
Author: xinao_seven_
Date: 2022-11-07 14:44:51
LastEditTime: 2022-11-07 14:47:12
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\main\\hash..py

'''
import hashlib

md = "shabi"

hl = hashlib.md5()

hl.update(md.encode(encoding='utf-8'))
print(hl.hexdigest())