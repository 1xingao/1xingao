'''
Author: xinao_seven_
Date: 2023-01-15 11:25:12
LastEditTime: 2023-01-15 11:26:12
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\main\\new.py

'''

from typing import List
def rangeAddQueries(n: int, queries: List[List[int]]) -> List[List[int]]:
    mat = []
    for que in queries:
        for i in range(que[0],que[2]+1):
            for j in range(que[1],que[3]+1):
                mat[i][j]+=1
    return mat

rangeAddQueries(3,[[1,1,2,2],[0,0,1,1]])