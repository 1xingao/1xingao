/*
 * @Author: xinao_seven_
 * @Date: 2022-09-18 10:23:40
 * @LastEditTime: 2022-09-18 10:57:58
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\leetcode_debug\\code_311.cpp
 * 
 */
#include<bits/stdc++.h>

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

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int flag=1;
        while(!que.empty()){
            int n = que.size();
            vector<int> val ;
            queue<TreeNode*> temp;
            for(int i=0;i<n;i++){
                TreeNode* node = que.front();
                que.pop();
                temp.push(node);
                val.push_back(node->val);
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }

                
            }
            if(flag == -1){
                reverse(val.begin(),val.end());
                for(int i=0;i<val.size();i++){
                    TreeNode* node= temp.front();
                    temp.pop();
                    node->val = val[i];
                }
            }
            
            flag*=-1;
        }
        return root;
    }
};

int main()
{
    Solution test;
    
    return 0;
}