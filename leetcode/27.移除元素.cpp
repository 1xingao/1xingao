/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int j = 0;
        if (len == 0 )
            return 0;
        for (int i = 0;i<len;i++){
            if (nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
                
        }
        return j;
    }
};
// @lc code=end

