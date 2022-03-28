#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<queue>
//自定义sort排序方式
using namespace std;
class Solution1 {
public:
    string frequencySort(string s) {
        unordered_map<char,int>hash;
        for(auto& x:s){
            hash[x]++;
        }
        vector<pair<char,int>>res(hash.begin(),hash.end());
        sort(res.begin(),res.end(),[](pair<char,int> a,pair<char,int> b){//lamb
            return a.second>b.second;
        });
        string rns;
        for(auto a:res){
            for(int i=0;i<a.second;i++){
                rns.push_back(a.first);
            }
        }
        return rns;

    }
};
//以普通函数的方式实现自定义排序规则
bool mycomp(int i, int j) {
    return (i < j);
}
//以函数对象的方式实现自定义排序规则
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i < j);
    }
};
//快速排序
void qsort(vector<int>& nums,int begin,int end)
    {
        if(begin<end){
            int key = nums[begin];
            int i = begin;
            int j = end;
            while(i<j){
                while(i<j&&nums[j]>key){
                    j--;
                }
                if(i<j){
                    nums[i] = nums[j];
                    i++;
                }
                while(i<j&&nums[i]<key){
                    i++;
                }
                if(i<j){
                    nums[j] = nums[i];
                    j--;
                }
            }
            nums[i] = key;
            qsort(nums,begin,i-1);
            qsort(nums,i+1,end);

        }
    }
//广度优先遍历
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
//二分查找
class Solution3 {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            int num = nums[mid];
            if (num == target) {
                return mid;
            } else if (num > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
}
