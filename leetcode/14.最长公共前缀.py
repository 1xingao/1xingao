#
# @lc app=leetcode.cn id=14 lang=python3
#
# [14] 最长公共前缀
#

# @lc code=start
from ast import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        re_list = strs[0]
        for i_str in range(1,len(strs)):
            pan_str = strs[i_str]
            for j in range(len(strs[i_str])):
                
                if j<len(re_list) and pan_str[j] != re_list[j]:
                    re_list = re_list[0:j]
            if len(re_list)>len(pan_str):
                re_list = re_list[0:len(pan_str)]
        return re_list
            
# @lc code=end

