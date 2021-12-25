/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if(!root->left&&!root->right){return true;}
        if(root->left==nullptr||root->right==nullptr){return false;}
        if(root->left->val==root->right->val){return check(root->left,root->right);}
        return false;
        
    }
    bool check(TreeNode* l,TreeNode* r)
    {
        if(!l&&!r){return true;}//左右子树都不存在对称
        if(!l || !r){return false;}//左右子树有一个不存在则不对称
        //两点的数据相等并且左子树
        return l->val==r->val&&check(l->left,r->right)&&check(l->right,r->left);
    }
};
// @lc code=end

