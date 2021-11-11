#include<vector>
using namespace std;
//树的中序遍历
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> ans;

    int kthSmallest(TreeNode *root, int k)
    {
        terr(root);
        return ans[k - 1];
    }
    void terr(TreeNode *tree)
    {
        if (tree != nullptr)
        {
            terr(tree->left);
            ans.push_back(tree->val);//执行到最下边的子节点回保存数据
            terr(tree->right);
        }
    }
};
int main()
{
    Solution c1();
    return 0;
}