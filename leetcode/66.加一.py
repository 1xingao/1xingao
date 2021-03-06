# @before-stub-for-debug-begin
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#

# @lc code=start



class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        lenth = len(digits)
        digits[lenth -1] +=1
        digits.reverse()
        for i in range(lenth):
            if digits[lenth - 1] == 10:
                digits[lenth-1] = 0
                digits.append(1)
                break
            if digits[i] >= 10:
                digits[i] -= 10
                digits[i+1] +=1
        digits.reverse()
        return digits

# @lc code=end

