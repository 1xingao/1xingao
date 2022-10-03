/*
 * @Author: xinao_seven_
 * @Date: 2022-07-14 11:26:46
 * @LastEditTime: 2022-10-03 17:01:36
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

//前缀树/字典树的实现
class Trie
{
public:
    bool end; //是否为结尾
    vector<Trie *> children;
    Trie() : children(26), end(false) {}

    void insert(string word)
    {
        Trie *temp = this;
        for (char c : word)
        {
            if (temp->children[c - 'a'] == nullptr)
            {
                temp->children[c - 'a'] = new Trie();
            }
            temp = temp->children[c - 'a'];
        }
        temp->end = true;
    }

    bool search(string word)
    {
        Trie *temp = this;
        for (char c : word)
        {
            if (temp->children[c - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[c - 'a'];
        }
        return temp->end;
    }

    bool startsWith(string prefix)
    {
        Trie *temp = this;
        for (char c : prefix)
        {
            if (temp->children[c - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[c - 'a'];
        }
        return true;
    }
    bool startwithdot(string word)
    {
        return dfs(this, word, 0);
    }
    /// @brief 匹配含有占位符的单词如.bac/ab.c
    /// @param root
    /// @param word
    /// @param index
    /// @return 是否存在这个单词(含占位符)
    bool dfs(Trie *root, string word, int index)
    {
        if (index >= word.size())
        {
            return root->end;
        }
        char c = word[index];
        if (c != '.')
        {
            if (root->children[c - 'a'] != nullptr)
            {
                return dfs(root->children[c - 'a'], word, index + 1);
            }
            else
            {
                return false;
            }
        }
        for (Trie *temp : root->children)
        {
            if (temp != nullptr && dfs(temp, word, index + 1))
            {
                return true;
            }
        }
        return false;
    }
};

//字典树实现前缀和后缀查找
class WordFilter
{
public:
    struct Trie
    {
        vector<int> idxs;
        Trie *children[26]{nullptr};
    };
    Trie *t1 = new Trie();
    Trie *t2 = new Trie();
    void insert(Trie *p, string &word, int idx, bool isturn)
    {
        int n = word.size();
        p->idxs.push_back(idx);
        for (int i = isturn ? n - 1 : 0; i >= 0 && i < n; i += isturn ? -1 : 1)
        {
            if (!p->children[word[i] - 'a'])
            {
                p->children[word[i] - 'a'] = new Trie();
            }
            p = p->children[word[i] - 'a'];
            p->idxs.push_back(idx);
        }
    }
    int battle(string &a, string &b)
    {
        int n = a.size(), m = b.size();
        auto p = t1;
        for (int i = 0; i < n; i++)
        {
            int u = a[i] - 'a';
            if (p->children[u] == nullptr)
            {
                return -1;
            }
            p = p->children[u];
        }
        vector<int> &temp1 = p->idxs;
        p = t2;
        for (int i = m - 1; i >= 0; i--)
        {
            int u = b[i] - 'a';
            if (p->children[u] == nullptr)
            {
                return -1;
            }
            p = p->children[u];
        }
        vector<int> &temp2 = p->idxs;
        int e = temp1.size(), f = temp2.size();
        for (int i = e - 1, j = f - 1; i >= 0 && j >= 0;)
        {
            if (temp1[i] > temp2[j])
            {
                i--;
            }
            else if (temp1[i] < temp2[j])
            {
                j--;
            }
            else
            {
                return temp1[i];
            }
        }
        return -1;
    }
    /// @brief
    /// @param words
    WordFilter(vector<string> &words)
    {
        int s = words.size();
        for (int i = 0; i < s; i++)
        {
            insert(t1, words[i], i, false);
            insert(t2, words[i], i, true);
        }
    }

    int f(string pref, string suff)
    {
        return battle(pref, suff);
    }
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

int main()
{
    string test = "i am a good!";
    auto res = split(test, " ");
    for (string s : res)
    {
        cout << s << endl;
    }
    return 0;
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

class decimalConversion
{
public:
    //十进制转化为任意进制

    /**
     * @description:
     * @param {int} digital
     * @param {int} r
     * @return {*}
     */
    std::string dtox(int digital, int r)
    {
        string result = "";
        const char s[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
        if (digital == 0)
        {
            return "0";
        }
        while (digital != 0)
        {
            int tmp = digital % r;
            result += s[tmp];
            digital /= r;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

void stl_func()
{
    vector<int> nums{1, 2, 3, 4, 5, 6};
    int res = accumulate(nums.begin(), nums.end(), 0); //计算元素和
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

//并查集

class ConcurrentSearch{
public:
    vector<int> fa, rank;
    ConcurrentSearch():fa(5005),rank(5005){}
    ConcurrentSearch(vector<int> & ph)
    {
        int n = fa.size();
        fa = vector<int>(n+1);
        rank = vector<int>(n+1);
    }
    //根据初始化不同需要更改并查集的第一数字起点
    void init(int n,int start)
    {
        for(int i=start;i<=n;i++){
            fa[i] = i;
            rank[i] = 1;
        }
    }
    //路径压缩
    int find(int x){
        return x == fa[x] ? x:(fa[x] = find(fa[x]));
    }
    //按秩排序写法
    void merge(int i,int j)
    {
        int x = find(i),y = find(j);

        if(rank[x] <= rank[y]){
            fa[x] = y;
            
        }else{
            fa[y] = x;
        }
        if(rank[x] == rank[y] && x!=y){rank[y]++;}
    }

    //正常写法
    int find(vector<int>& fa,int x){
        return x == fa[x] ? x:(fa[x] = find(fa,fa[x]));
    }
    
    void merge(vector<int>& fa,int i,int j)
    {
        int x = find(fa,i),y = find(fa,j);

        fa[x] = y;
    }

    
};