/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];
        //摩尔投票法，众数个数至少比非众数多一，
        //把COUNT加减当作一个众数抵消掉一个非众数，剩下的一定是众数
        int res ;
        int count = 0;
        for(int num:nums){
            if(count ==0){res = num;}
            if(num == res){
                count++;
            }
            else{
                count--;
            }
        }
        return res;
    }
};
// @lc code=end

