#include<queue>
#include<stack>
#include<vector>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//广度优先遍历
std::vector<int> bfs(TreeNode* root)
{
    std::vector<int> re;
    std::queue<TreeNode*> nodequeue;
    nodequeue.push(root);
    TreeNode* node;
    while(!nodequeue.empty()){

        node = nodequeue.front();
        nodequeue.pop();
        re.push_back(node->val);

        if(node->left!=nullptr){
            nodequeue.push(node->left);
        }
        if(node->right!=nullptr){
            nodequeue.push(node->right);
        }
    }
    return re;
}