'''
Author: xinao_seven_
Date: 2024-08-14 11:55:42
LastEditTime: 2024-09-11 17:38:24
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \1xingao\python\main\test.py

'''
from typing import List
from collections import Counter
class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        s = [0 for _ in range(len(nums))]
        for i in range(1,len(nums)):
            s[i] = s[i-1] + 1 if nums[i]&1 == nums[i-1]&1 else 0
        res = []
        for i in range(len(queries)):
            if s[queries[i][0]] == s[queries[i][1]]:
                res.append(True)
            else:
                res.append(False)
        return res


class Solution1:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        
        hash = dict(Counter(nums))
        target = sum(nums)//k
        if max(nums) >k:
            return False
        val = hash.keys().sort(reverse=True)
        fin = []
        for i in range(len(val)):
            if(val[i] == target ) or val[i] in fin:
                fin.append(val[i])
                continue
            if ((target-val[i]) in val) and (hash[target-val[i]]==hash[val[i]]):
                fin.append(target-val[i])
                fin.append(val[i])
        return len(val) == len(hash.key())

class Solution2:
    def maxArea(self, height: List[int]) -> int:
        hig = [[0,0] for _ in range(len(height))]
        right_max = height[-1]
        right_index = len(height)-1
        for i in range(len(height)-1,-1,-1):
            hig[i][0] = right_max
            hig[i][1] = right_index
            if right_max < height[i] :

                right_max = height[i]
                right_index = i
        res = 0
        for i in range(len(height)-1):
            res = max(res,min(height[i],hig[i][0])*(hig[i][1]-i))
        return res
class Solution3:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        right_max = [0 for _ in range(n)]
        left_max = [0 for _ in range(n)]
        res = 0

        left_max[0] = height[0]
        right_max[-1] = height[-1]

        for i in range(1,n):
            left_max[i] = max(left_max[i-1],height[i-1])
        for i in range(n-2,-1,-1):
            right_max[i] = max(right_max[i+1],height[i+1])
        
        for i in range(0,n):
            if min(left_max[i], right_max[i]) <= height[i]:
                continue
            res += min(left_max[i],right_max[i])-height[i]
        return res
            
class Solutionx:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        direction = [[0,1],[1,0],[0,-1],[-1,0]]

        direction_cnt = 0
        res = []
        row = 0
        col = 0
        cnt = 0
        m,n = len(matrix),len(matrix[0])
        while(True):
            
                
            res.append(matrix[row][col])
            matrix[row][col] = 101
            
            row_next = row + direction[direction_cnt%4][0]
            col_next = col + direction[direction_cnt%4][1]
            if(0<=row_next<m and 0<=col_next<n and matrix[row_next][col_next]!=101):
                row += direction[direction_cnt%4][0]
                col += direction[direction_cnt%4][1]
            else:
                direction_cnt += 1
                row += direction[direction_cnt%4][0]
                col += direction[direction_cnt%4][1]
            cnt += 1
            if cnt == m*n:
                break
        return res


class Solutionx:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        temp = []
        def dfs(nums: List[int], used:List[int]):
            if len(nums) == len(temp):
                res.append(temp)
                return
            for i in range(len(nums)):
                if used[i] : continue
                temp.append(nums[i])
                used[i] = True
                dfs(nums,used)
                used[i] = False
                temp.pop()

        used = [False for _ in range(len(nums))]
        dfs(nums,used)
        
        return res
            
def main():
    test = Solutionx()
    test.permute([1,2,3])
    


if __name__ == "__main__":
    main()