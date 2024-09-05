'''
Author: xinao_seven_
Date: 2024-04-25 16:27:19
LastEditTime: 2024-05-13 18:00:35
LastEditors: xinao_seven_
Description: ,
Encoding: utf8
FilePath: \1xingao\python\main\leettest.py

'''
from typing import List


class Solution:
    def maxSum(self, nums: List[int]) -> int:
        data = []
        def getMAX(num:int)-> int:
            res = 0
            while(num):
                res = max(res,num%10)
                num = num//10
            return res
        for i in range(len(nums)):
            data.append(getMAX(nums[i]))
        res = -1
        for i in range(len(data)):
            for j in range(i+1,len(data)):
                if data[i] == data[j]:
                    res = max(res,nums[i]+nums[j])
        return res
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        res = 0
        left = capacityA
        right = capacityB
        for i in range(len(plants)//2):
            if left<plants[i]:
                left= capacityA
                res+=1
            else:
                left -= plants[i]
            if right < plants[len(plants)-i-1]:
                right= capacityB
                res+=1
            else:
                right -= plants[len(plants)-i-1]
        if len(plants)%2!=0:
            if max(left,right) < plants[len(plants)//2]:
                res +=1
        return res
class Solution1:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        data = []
        way = [ [0,1],[0,-1],[-1,0],[1,0]]
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j] == 2:
                    data.append([i,j])
        
        res = 0
        while(len(data)>0):
            res += 1
            n = len(data)
            for i in range(n):
                for j in range(4):
                    left = data[0][0]+way[j][0]
                    right = data[0][1]+way[j][1]
                    if left>=0 and right >=0 and left<len(grid) and right<len(grid):

                        cur = grid[left][right]
                    else:
                        continue
                    if cur == 1:
                        data.append([left,right])
                        grid[left][right] = 2
                data.pop(0)
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j] == 1:
                    return -1
        return res
s1 = Solution1()
nums = [[2,1,1],[1,1,0],[0,1,1]]
s1.orangesRotting(nums)