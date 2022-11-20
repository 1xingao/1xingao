/*
 * @Author: xinao_seven_
 * @Date: 2022-11-20 09:59:47
 * @LastEditTime: 2022-11-20 15:59:17
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\week320.cpp
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long  


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
    vector<int> nums;
    void dfs(TreeNode* root){
        if(root){
            dfs(root->left);
            nums.push_back(root->val);
            dfs(root->right);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        vector<vector<int>> res;
        for(int i=0;i<queries.size();i++){
            auto it = upper_bound(nums.begin(),nums.end(),queries[i]);
            int fir = it==nums.end()?-1:*it;
            auto it = lower_bound(nums.begin(),nums.end(),queries[i]);
            int sec = it==nums.begin()?-1:*it;
            res.push_back({fir,sec});
        }
        return res;
    }
};