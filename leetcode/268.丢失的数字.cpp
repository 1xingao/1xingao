/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<len;i++){
            if(nums[i]!= i){
                return i;
            }
        }
        return len;
    }
};
// @lc code=end

