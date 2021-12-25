/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // if(nums.size()==2){return (nums[0]-1)*(nums[1]-1);}
        // int maxs = min(nums[0],nums[1]);
        // int maxl =max(nums[0],nums[1]);
        // for(int i=2;i<nums.size();i++){
        //     if(nums[i]>maxs){//大于两数中小的那个是因为要更新小数
        //         maxs = min(nums[i],maxl);//必须先更新小数
        //         maxl = max(maxl,nums[i]);
               
        //     }
        // }
        // return (maxs-1)*(maxl-1);
        sort(nums.begin(),nums.end());
        return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
    }
};
// @lc code=end

