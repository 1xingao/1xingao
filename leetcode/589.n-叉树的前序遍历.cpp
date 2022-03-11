/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        // vector<int> res;
        // stack<Node*> mystack;
        // if(!root){return res;}
        // mystack.emplace(root);
        // while(!mystack.empty()){
        //     Node* node = mystack.top();
        //     mystack.pop();
        //     res.push_back(node->val);
        //     for(auto it = node->children.rbegin(); it != node->children.rend(); it++){
        //         mystack.emplace(*it);
        //     }
        // }
        // return res;
        //上面是迭代算法
        
        dfs(root);
        return res;
        
    }
    void dfs(Node* root)
    {
        if(!root){
            return;
        }
        res.push_back(root->val);
        for(auto x:root->children){
            dfs(x);
        }
    }
};
// @lc code=end

