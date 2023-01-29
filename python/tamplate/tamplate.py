'''
Author: xinao_seven_
Date: 2023-01-01 12:22:53
LastEditTime: 2023-01-01 12:44:48
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\tamplate\\tamplate.py

'''
# 

from functools import lru_cache
import math
@lru_cache(None)
def get_prime_factor(num):
    # 质因数分解
    res = []
    for i in range(2, int(math.sqrt(num)) + 1):
        cnt = 0
        while num % i == 0:
            num //= i
            cnt += 1
        if cnt:
            res.append([i, cnt])
        if i > num:
            break
    if num != 1 or not res:
        res.append([num, 1])
    # 从小到大返回质因数分解以及对应的幂次，注意 1 返回 []
    return res
