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
    Trie() : children(26), end(false){}

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
//leetcode6，z字形变换
class Solution1
{
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<string> res(numRows);
        int flag = 1;
        int row = 0;
        for(int i=0;i<s.size();i++){
            res[row]+=s[i];
            row+=flag;
            if(row == numRows-1||row ==0){
                flag = -flag;
            }
        }
        string ret;
        for(string re:res){
            ret+=re;
        }
        return ret;
    }
};

//split函数，仅适用于string
const std::vector<std::string> split(const std::string& str, const std::string& pattern)
{
    std::vector<std::string> result;
    std::string::size_type begin, end;

    end = str.find(pattern);
    begin = 0;

    while (end != std::string::npos) {
        if (end - begin != 0) {
            result.push_back(str.substr(begin, end-begin)); 
        }    
        begin = end + pattern.size();
        end = str.find(pattern, begin);
    }

    if (begin != str.length()) {
        result.push_back(str.substr(begin));
    }
    return result;
}

int main()
{
    string test = "i am a good!";
    auto res = split(test," ");
    for(string s:res){
        cout<<s<<endl;
    }
    return 0;
}