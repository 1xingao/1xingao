/*
 * @Author: xinao_seven_
 * @Date: 2022-07-14 11:26:46
 * @LastEditTime: 2022-11-20 16:36:13
 * @LastEditors: xinao_seven_
 * @Description:
 * @FilePath: \\1xingao\\cpp\\new_soluation.cpp
 *
 */
#include <bits/stdc++.h>
using namespace std;
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


/*
不用看官方题解，那么复杂。 所有树的题目，都想成一颗只有根、左节点、右节点 的小树。然后一颗颗小树构成整棵大树，
所以只需要考虑这颗小树即可。接下来分情况， 按照题意：一颗三个节点的小树的结果只可能有如下6种情况：

根 + 左 + 右
根 + 左
根 + 右
根
左
右
好了，分析上述6种情况， 只有 2,3,4 可以向上累加，而1,5,6不可以累加（这个很好想，
情况1向上累加的话，必然出现分叉，情况5和6直接就跟上面的树枝断开的，没法累加），
所以我们找一个全局变量存储 1,5,6这三种不可累加的最大值， 另一方面咱们用遍历树的方法求2,3,4这三种可以累加的情况。
 最后把两类情况得到的最大值再取一个最大值即可。
 */

class Solution3
{
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        int n = sear(root);
        return max(res, n);
    }
    int sear(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = max(0, sear(root->left));
        int right = max(0, sear(root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};
/**
 * 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个
 * 节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。


 *
 */

//单调队列解决滑动窗口最大值
//单调队列使用的是双端队列
class Solution2
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> que;
        vector<int> res;
        int i;
        //先将k的单调队列填满
        //单调队列并不一定size == k只是队列中的元素保持单调递减(从队头到队尾)
        for (i = 0; i < k; i++)
        {
            while (!que.empty() && que.back() < nums[i])
            {
                que.pop_back();
            }
            que.push_back(nums[i]);
        }
        res.push_back(que.front());
        while (i < nums.size())
        {
            if (que.front() == nums[i - k])
            {
                que.pop_front();
            }
            while (!que.empty() && que.back() < nums[i])
            {
                que.pop_back();
            }
            que.push_back(nums[i++]);
            res.push_back(que.front());
        }
        return res;
    }
};

//构造二维数组可以使用string状态压缩
// leetcode6，z字形变换
class Solution1
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> res(numRows);
        int flag = 1;
        int row = 0;
        for (int i = 0; i < s.size(); i++)
        {
            res[row] += s[i];
            row += flag;
            if (row == numRows - 1 || row == 0)
            {
                flag = -flag;
            }
        }
        string ret;
        for (string re : res)
        {
            ret += re;
        }
        return ret;
    }
};

// split函数，仅适用于string
const std::vector<std::string> split(const std::string &str, const std::string &pattern)
{
    std::vector<std::string> result;
    std::string::size_type begin, end;

    end = str.find(pattern);
    begin = 0;

    while (end != std::string::npos)
    {
        if (end - begin != 0)
        {
            result.push_back(str.substr(begin, end - begin));
        }
        begin = end + pattern.size();
        end = str.find(pattern, begin);
    }

    if (begin != str.length())
    {
        result.push_back(str.substr(begin));
    }
    return result;
}


class Solution_for_bfs
{
public:
    //二维矩阵的bfs
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != 0)
            return -1;
        if (grid[n - 1][m - 1] == 1)
            return -1;
        if (n == 1)
            return 1;

        int dir[8][8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1}};
        queue<pair<int, int>> que;
        que.push({0, 0});
        int res = 1;
        grid[0][0] = 1;
        while (!que.empty())
        {
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for (int j = 0; j < 8; j++)
                {
                    int xx = x + dir[j][0];
                    int yy = y + dir[j][1];

                    if (xx >= 0 && xx < n && yy >= 0 && yy < m)
                    {
                        if (grid[xx][yy] == 0)
                        {
                            que.push({xx, yy});
                            grid[xx][yy] = 1;
                        }
                    }
                    if (xx == n - 1 && yy == m - 1)
                    {
                        return res + 1;
                    }
                }
            }
            res++;
        }
        return -1;
    }
    //二维矩阵的dfs
    void dfs(vector<vector<char>> &grid, int row, int col)

    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            grid[row][col] != '1')
        { //这里必须判断标记值不然会无限递归
            return;
        }
        grid[row][col] = '2';
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};
//状态压缩用二进制遍历 leetcode805
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int m = n/2;
        if(n==1){return false;}
        for(auto &x:nums){
            x = x*n-sum;//对平均值进行运算
        }
        unordered_set<int> left;
        for(int i=1;i<(1<<n/2);i++){
            int to = 0;
            for(int j=0;j<m;j++){
                if(i&(1<<j)){
                    to += nums[j];
                }
            }
            if(to == 0){
                return true;
            }
            left.insert(to);
        }
        int rsum = accumulate(nums.begin()+m,nums.end(),0);
        
        for(int i=1;i<(1<<n-m);i++){
            int to = 0;
            for(int j=m;j<n;j++){
                if(i&(1<<j-m)){
                    to += nums[j];
                }
            }
            if(to == 0 || rsum!=to && left.count(-to)){
                return true;
            }
            
        }
        return false;

    }
};
//寻找二叉树路径包含Y字型

class Solution_for_tree
{
public:
    int res = 0;
    int longestUnivaluePath(TreeNode *root)
    {

        dfs(root);
        return res;
    }
    int dfs(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);

        if (root->left && root->val == root->left->val)
        {
            left++;
        }
        else
        {
            left = 0;
        }
        if (root->right && root->val == root->right->val)
        {
            right++;
        }
        else
        {
            right = 0;
        }
        res = max(res, right + left);
        return max(right, left);
    }
};

void stl_func()
{
    vector<int> nums{1, 2, 3, 4, 5, 6};
    int res = accumulate(nums.begin(), nums.end(), 0); //计算元素和
    auto max_iter = max_element(nums.begin(),nums.end());
    //第一个大于三的值的迭代器
    int index = upper_bound(nums.begin(),nums.end(),3)-nums.begin();
}

//获取数组里面的最大值和他后边的次大值
bool increasingTriplet(vector<int> &nums)
{
    int a = INT_MAX;
    int b = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= a)
        {
            a = nums[i];
        }
        else if (nums[i] <= b)
        {
            b = nums[i];
        }
        else
        {
            return true;
        }
    }
    return false;
}
//前缀和求 [i,j] 的和就是 前缀和数组的preSum[j+1]-preSum[i]
static const int MAXP = 30;
void bits_fun()
{
    int num1 = 134;
    //求num1的二级制表示
    int A[MAXP + 1] = {0};
    for (int i = MAXP; i >= 0; i--) A[i] = num1 >> i & 1;

}

using namespace std;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event1[1].substr(0,2) < event2[0].substr(0,2)){
            return false;
        }else if(event1[1].substr(0,2) == event2[0].substr(0,2)){
            return event1[1].substr(3,2) >event2[0].substr(3,2);
        }
        if(event1[0].substr(0,2) > event2[1].substr(0,2)){
            return false;
        }else if(event1[0].substr(0,2) == event2[1].substr(0,2)){
            return event1[0].substr(3,2) < event2[1].substr(3,2);
        }
        return true;
    }
};

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                for(int j=i;j<nums.size();j++){
                    if(__gcd(nums[i],nums[j])==k){
                        res++;
                    }else{
                        break;
                    }
                }
            }
        }
        return res;
        
        
    }
};

//二维矩阵前缀和
class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        pre = vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size()+1));
        for(int i=1;i<matrix.size()+1;i++){
            for(int j=1;j<=matrix[0].size();j++){
                pre[i][j] = pre[i-1][j]+pre[i][j-1]+matrix[i-1][j-1]-pre[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2+1][col2+1] - pre[row1][col2+1]-pre[row2+1][col1]+pre[row1][col1];
    }
};


//求最小公倍数
int lcm(int a, int b) {
    return a*b / gcd(a, b);//最大公约数 
}

/*
upper_bound 是大于
lower_bound 是大于等于
upper_bound -1 就是小于等于

auto [it2, it1] = equal_range(arr.begin(), arr.end(), query);
it2 upper_bound , it1 lower_bound
*/
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
            
            if(nums[0]>queries[i]){
                res.push_back({-1,nums[0]});
                continue;
            }
            if(nums[nums.size()-1]<queries[i]){
                res.push_back({nums[nums.size()-1],-1});
                continue;
            }

            auto it = upper_bound(nums.begin(),nums.end(),queries[i]);
            auto it2 = lower_bound(nums.begin(),nums.end(),queries[i]);
            
            res.push_back({*(it-1),*(it2)});
        }
        return res;
    }
};