#include<bits/stdc++.h> 
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
            nums[i] = key;//先移动j后移动i
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
};
//归并排序
class Solution4 {
public:
    void merge(vector<int>& nums, int begin, int mid, int end) {
        vector<int> tmp(end - begin + 1);
        int i = begin, j = mid + 1, k = 0;
        while(i <= mid && j <= end){
            if(nums[i] < nums[j]){
                tmp[k++] = nums[i++];
            }else{
                tmp[k++] = nums[j++];
            }
        }
        while(i <= mid){
            tmp[k++] = nums[i++];
        }
        while(j <= end){
            tmp[k++] = nums[j++];
        }
        for(int i = 0; i < tmp.size(); i++){
            nums[begin + i] = tmp[i];
        }
    }
    void mergeSort(vector<int>& nums, int begin, int end) {
        if(begin < end){
            int mid = (end - begin) / 2 + begin;
            mergeSort(nums, begin, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, begin, mid, end);
        }
    }
    void mergeSort(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }
};
//查找公用字符(哈希表)
class Solution5{
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>res;
        int hash[26] = {0};//用于存储最小出现次数的哈希表
        for(int i=0;i<words[0].size();i++){
            hash[words[0][i]-'a']++;//第一个作为初始化
        }
        for(int j=1;j<words.size();j++){
            int arr[26] = {0};
            for(int k=0;k<words[j].size();k++){//每次遍历会找出这个str每个字符出现的次数
                arr[words[j][k]-'a']++;
            }
            for(int c=0;c<26;c++){
                hash[c] = min(hash[c],arr[c]);//获取最小次数，因为字符可以重复
            }
        }
        for(int i=0;i<26;i++){
            while(hash[i]){//每个字符不止出现一次
                string s(1, i + 'a');//char->string
                res.push_back(s);
                hash[i]--;
            }
        }
        return res;
    }
};

//单调队列递减(左边值大于右边)
class Myqueue{
    public:
    deque<int> que;
    void pop(int value)
    {
        if(!que.empty()&&que.front()==value){
            que.pop_front();
        }
    }
    void push(int value)
    {
        while(!que.empty()&&que.back()< value){
            que.pop_back();
        }
        que.push_back(value);
    }
    int front()
    {
        return que.front();
    }
};
//优先队列
class Solution6 {
public:
//小顶堆
    priority_queue <int,vector<int>,greater<int> > q;
//大顶堆
    priority_queue <int,vector<int>,less<int> >q;
//默认大顶堆
    priority_queue<int> a;
//自定义函数比较
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        struct mycmp{
            bool operator()( const pair<int,int>& p1,const pair<int,int>& p2){
                return p1.second>p2.second;
            }
        };
        unordered_map<int,int> hash;
        for(int i:nums){
            hash[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> que;
        //小顶堆的构建三个参数分别是类型，底层类型，自定义比较函数
        for(auto& a:hash){
            que.push(a);
            if(que.size()>k){
                que.pop();
            }
        }
        vector<int>res;
        while(!que.empty()){
            res.emplace_back(que.top().first);
            que.pop();
        }
        return res;
    }
};