/*
 * @Author: xinao_seven_
 * @Date: 2022-09-25 10:23:34
 * @LastEditTime: 2022-09-25 11:15:29
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\code_weekend.cpp
 * 
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> res;
        for(int i=k;i<n-k;i++){
            bool falg = true;
            for(int j=i-k;j<i;j++){
                if(falg &&nums[j] > nums[j+1]){
                    falg = false;
                }
            }
            for(int j=i;j<i+k;j++){
                if(falg&&nums[j] > nums[j+1]){
                    falg = false;
                }
            }
            if(falg){res.push_back(i);}
        }
        return res;
    }
};


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> dp1(nums.size(),0);
        vector<int> dp2(nums.size(),0);
        dp1[0] = nums[0];
        dp2[nums.size()-1] = dp2[nums.size()-1];
        int n = nums.size();
        for(int i=1;i<nums.size();i++){
            dp1[i] = dp1[i-1]&nums[i];
            dp2[n-i-1] = dp2[n-i]&nums[n-i-1];
        }
        int res  = 0;
        for(int i=1;i<nums.size()-1;i++){
            res = max(res,dp1[i-1]);
        }
    }
};

int main()
{
    return 0;
}