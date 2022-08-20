/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
 */
#include <bits/stdc++.h>
//自定义sort排序方式
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        vector<int> sum;
        while(!que.empty()){
            int n = que.size();
            int sumn = 0;
            for(int i=0;i<n;i++){
                TreeNode* node = que.front();
                que.pop();
                sumn+=node->val;
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            sum.push_back(sumn);
        }
        int m = INT_MIN;
        for(int i=0;i<sum.size();i++){
            m = max(m,sum[i]);
            if(m==sum[i]){
                res = i+1;
            }
        }
        return res;
        
    }
};
// @lc code=end

