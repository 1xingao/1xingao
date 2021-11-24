/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count= 0;
        for (int i = 0;i<nums.size();i++){
            int temp = nums[i];
            count = 0;
            for(int j =0;j<nums.size();j++){
                if (nums[i]==nums[j]&&j!=i)
                    count = 1;
            }
            if (count == 0)
            return temp;
        }
        return 0;
    }
};
// @lc code=end

