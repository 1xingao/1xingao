/*
 * @Author: xinao_seven_
 * @Date: 2022-09-27 19:23:07
 * @LastEditTime: 2022-09-28 20:13:22
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\code_1007.cpp
 * 
 */
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = INT_MIN;
        int left = 0;
        int right = 0;
        while (right < nums.size()){
            if(nums[right++]==0){
                k--;
            }
            while(k<0){
                if(nums[left++]==0){
                    k++;
                }

            }
            res = max(res,right-left);
        }
        return res;
    }
};




int main()
{
    Solution test;
    vector<int> t {1,1,1,0,0,0,1,1,1,1,0};
    test.longestOnes(t,2);
    return 0;
}