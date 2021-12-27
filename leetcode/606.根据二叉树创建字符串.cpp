/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

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
    string all;
    string tree2str(TreeNode* root) {
        find(root);
        return all;
    }
    void find(TreeNode* root)
    {
        
        if(root!=nullptr){
            all+=to_string(root->val);
            if(root->left==nullptr&&root->right!=nullptr){
                    all+="()";}
            
            if(root->left!=nullptr){
                all+="(";
                find(root->left);
                all+=")";
            }
            
            if(root->right!=nullptr){
                all+="(";
                find(root->right);
                all+=")";
            }
            
        }
    }
};
// @lc code=end

