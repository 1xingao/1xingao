#include <bits/stdc++.h>
//自定义sort排序方式
using namespace std;
class Solution1
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> hash;
        for (auto &x : s)
        {
            hash[x]++;
        }
        vector<pair<char, int>> res(hash.begin(), hash.end());
        sort(res.begin(), res.end(), [](pair<char, int> a, pair<char, int> b) { // lamb
            return a.second > b.second;
        });
        string rns;
        for (auto a : res)
        {
            for (int i = 0; i < a.second; i++)
            {
                rns.push_back(a.first);
            }
        }
        return rns;
    }
};
//以普通函数的方式实现自定义排序规则
static bool mycomp(int i, int j)
{
    return (i < j);
}
//以函数对象的方式实现自定义排序规则
class mycomp2
{
public:
    bool operator()(int i, int j)
    {
        return (i < j);
    }
};
//快速排序
void qsort(vector<int> &nums, int begin, int end)
{
    if (begin < end)
    {
        int key = nums[begin];
        int i = begin;
        int j = end;
        while (i < j)
        {
            while (i < j && nums[j] > key)
            {
                j--;
            }
            if (i < j)
            {
                nums[i] = nums[j];
                i++;
            }
            while (i < j && nums[i] < key)
            {
                i++;
            }
            if (i < j)
            {
                nums[j] = nums[i];
                j--;
            }
        }
        nums[i] = key; //先移动j后移动i
        qsort(nums, begin, i - 1);
        qsort(nums, i + 1, end);
    }
}
//二叉树的通用删除节点的方法
class Solution9
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root;
        if (root->val == key)
        {
            if (root->right == nullptr)
            { // 这里第二次操作目标值：最终删除的作用
                return root->left;
            }
            TreeNode *cur = root->right;
            while (cur->left)
            {
                cur = cur->left;
            }
            swap(root->val, cur->val); // 这里第一次操作目标值：交换目标值其右子树最左面节点。
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};
//广度优先遍历
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> bfs(TreeNode *root)
{
    std::vector<int> re;
    std::queue<TreeNode *> nodequeue;
    nodequeue.push(root);
    TreeNode *node;
    while (!nodequeue.empty())
    {

        node = nodequeue.front();
        nodequeue.pop();
        re.push_back(node->val);

        if (node->left != nullptr)
        {
            nodequeue.push(node->left);
        }
        if (node->right != nullptr)
        {
            nodequeue.push(node->right);
        }
    }
    return re;
}
//二分查找
class Solution3
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
            int num = nums[mid];
            if (num == target)
            {
                return mid;
            }
            else if (num > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};
//归并排序
class Solution4
{
public:
    void merge(vector<int> &nums, int begin, int mid, int end)
    {
        vector<int> tmp(end - begin + 1);
        int i = begin, j = mid + 1, k = 0;
        while (i <= mid && j <= end)
        {
            if (nums[i] < nums[j])
            {
                tmp[k++] = nums[i++];
            }
            else
            {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid)
        {
            tmp[k++] = nums[i++]
        }
        while (j <= end)
        {
            tmp[k++] = nums[j++];
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            nums[begin + i] = tmp[i];
        }
    }
    void mergeSort(vector<int> &nums, int begin, int end)
    {
        if (begin < end)
        {
            int mid = (end - begin) / 2 + begin;
            mergeSort(nums, begin, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, begin, mid, end);
        }
    }
    void mergeSort(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
    }
};
//查找公用字符(哈希表)
class Solution5
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> res;
        int hash[26] = {0}; //用于存储最小出现次数的哈希表
        for (int i = 0; i < words[0].size(); i++)
        {
            hash[words[0][i] - 'a']++; //第一个作为初始化
        }
        for (int j = 1; j < words.size(); j++)
        {
            int arr[26] = {0};
            for (int k = 0; k < words[j].size(); k++)
            { //每次遍历会找出这个str每个字符出现的次数
                arr[words[j][k] - 'a']++;
            }
            for (int c = 0; c < 26; c++)
            {
                hash[c] = min(hash[c], arr[c]); //获取最小次数，因为字符可以重复
            }
        }
        for (int i = 0; i < 26; i++)
        {
            while (hash[i])
            {                         //每个字符不止出现一次
                string s(1, i + 'a'); // char->string
                res.push_back(s);
                hash[i]--;
            }
        }
        return res;
    }
};

//单调队列递减(左边值大于右边)
class Myqueue
{
public:
    deque<int> que;
    void pop(int value)
    {
        if (!que.empty() && que.front() == value)
        {
            que.pop_front();
        }
    }
    void push(int value)
    {
        while (!que.empty() && que.back() < value)
        {
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
class Solution6
{
public:
    //小顶堆
    priority_queue<int, vector<int>, greater<int>> q;
    //大顶堆
    priority_queue<int, vector<int>, less<int>> q;
    //默认大顶堆
    priority_queue<int> a;
    //自定义函数比较
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        struct mycmp
        {
            bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
            {
                return p1.second > p2.second;
            }
        };
        unordered_map<int, int> hash;
        for (int i : nums)
        {
            hash[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> que;
        //小顶堆的构建三个参数分别是类型，底层类型，自定义比较函数
        for (auto &a : hash)
        {
            que.push(a);
            if (que.size() > k)
            {
                que.pop();
            }
        }
        vector<int> res;
        while (!que.empty())
        {
            res.emplace_back(que.top().first);
            que.pop();
        }
        return res;
    }
};
//回溯算法去重
//回溯算法去重要求同一行使用过的不能使用，但是同一树枝使用过的可以使用
class Solution7
{
public:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int> &nums, int start, vector<bool> used)
    {
        if (start > nums.size())
        {
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            { //不用used直接让i！=start也行
                continue;
            }
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 而我们要对同一树层使用过的元素进行跳过
            //上边传递下来的i-1一定是true，传参是i+1
            temp.push_back(nums[i]);
            used[i] = true;
            res.push_back(temp);
            dfs(nums, i + 1, used);
            used[i] = false;
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false); //用于保存该数是否使用过
        dfs(nums, 0, used);
        res.push_back(vector<int>{}); //无关，这是求子集所以加一个空集
        return res;
    }
};
//二叉搜索树的插入
class Solution8
{
public:
    //插入
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        if (root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
    //删除
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
        if (root->val == key)
        {
            // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
            if (root->left == nullptr && root->right == nullptr)
            {
                ///! 内存释放
                delete root;
                return nullptr;
            }
            // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            else if (root->left == nullptr)
            {
                auto retNode = root->right;
                ///! 内存释放
                delete root;
                return retNode;
            }
            // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if (root->right == nullptr)
            {
                auto retNode = root->left;
                ///! 内存释放
                delete root;
                return retNode;
            }
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
            // 并返回删除节点右孩子为新的根节点。
            else
            {
                TreeNode *cur = root->right; // 找右子树最左面的节点
                while (cur->left != nullptr)
                {
                    cur = cur->left;
                }
                cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
                TreeNode *tmp = root;   // 把root节点保存一下，下面来删除
                root = root->right;     // 返回旧root的右孩子作为新root
                delete tmp;             // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
                return root;
            }
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};
// N皇后问题
class Nqueen
{
public:
    vector<vector<string>> res;
    bool isSet(int n, int row, int col, vector<string> checkerboard) //检查函数，检测放在这个位值是否合法
    {
        for (int i = 0; i < row; i++)
        {
            if (checkerboard[i][col] == 'Q')
            { //检查列
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (checkerboard[i][j] == 'Q')
            { //左对角
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (checkerboard[i][j] == 'Q')
            { //右对角
                return false;
            }
        }
        return true;
    }
    void dfs(int n, int row, vector<string> &checkerboard)
    {
        if (row == n)
        {
            res.push_back(checkerboard); //如果没有满足条件的回直接返回初始
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isSet(n, row, i, checkerboard))
            {
                checkerboard[row][i] = 'Q';
                dfs(n, row + 1, checkerboard);
                checkerboard[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> checkerboard(n, string(n, '.')); //初始化
        dfs(n, 0, checkerboard);
        return res;
    }
};
//贪心算法解决跳跃问题
class Solution9
{
public:
    int jump(vector<int> &nums)
    {
        int maxstep = 0; //记录当前能走到的最远距离
        int step = 0;    //记录所走的步数
        int end = 0;     //记录上一次能走到的最远距离
        if (nums.size() == 1)
        {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            maxstep = max(maxstep, i + nums[i]); //每次更新最远距离，因为直接跳到最远的不一定是最远的
            //中间有的可能回跳的更远
            if (maxstep >= nums.size() - 1)
            {
                return step + 1;
            }

            if (end == i)
            { //当前的i遍历到上次能跳到的最远位置
                end = maxstep;
                step++;
            }
        }
        return step;
    }
};

// typedef struct mystring{
//     char s[100];
//     int length;
// }mystring;
// void mystr(char *str)
// {
//     mystring *p = (mystring *)malloc(sizeof(mystring));
//     strcpy(p.s,str);
//     p.length = strlen(str);
// }
// void edit(str s[])
// {
//     while(true){
//         char tem[100];
//         std::cin >> tem;
//         if(strcmp(tem,"#")==0){
//             break;
//         }else{
//             strcpy(s[i].txt,tem);
//             i++;
//         }
//     }
// }
// 01背包问题
void test_2_wei_bag_problem1()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // 初始化
    for (int j = weight[0]; j <= bagweight; j++)
    {
        dp[0][j] = value[0];
    }

    // weight数组的大小 就是物品个数
    for (int i = 1; i < weight.size(); i++)
    { // 遍历物品
        for (int j = 0; j <= bagweight; j++)
        { // 遍历背包容量
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    cout << dp[weight.size() - 1][bagweight] << endl;
}

//如果求组合数就是外层for循环遍历物品，内层for遍历背包。

//如果求排列数就是外层for遍历背包，内层for循环遍历物品。
void test_o1bage()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};

    int bagweight = 4;
    vector<int> dp(bagweight + 1, 0);
    //滚动数组解决01背包问题
    for (int i = 0; i < weight.size(); i++)
    {
        for (int j = bagweight; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
}
//买卖股票的最佳时机4可进行最多k次操作
//我原称之为最强股票解法
class Solution10
{
public:
    //将III里面多个数组压缩成两个一维数组（滚动数组）
    //参考股票三优化版本，下边
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.size() == 0 || k == 0)
        {
            return 0;
        }
        vector<int> buy(k);  //第j次持有股票
        vector<int> sell(k); //不持有股票
        for (int i = 0; i < k; i++)
        {
            buy[i] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++)
        {
            //第一次买卖的时间
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for (int j = 1; j < k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]); // pricrs中参数为i是因为不确定第一次有没有持有该股票
                //第一次是取最大收益，所以后续每次都要尝试持有当前股票
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k - 1];
    }
};
//股票三的写法
class Solution11
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> dp1(prices.size()); //在第i天一次买入最大收益
        vector<int> dp2(prices.size()); //在第i天一次卖出最大收益
        vector<int> dp3(prices.size()); //在第i天二次买入最大收益
        vector<int> dp4(prices.size()); //在第i天二次卖出最大收益
        dp1[0] = dp3[0] = -prices[0];
        dp2[0] = dp4[0] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp1[i] = max(dp1[i - 1], -prices[i]);
            dp2[i] = max(dp1[i - 1] + prices[i], dp2[i - 1]);
            dp3[i] = max(dp2[i - 1] - prices[i], dp3[i - 1]);
            dp4[i] = max(dp3[i - 1] + prices[i], dp4[i - 1]);
        }
        return dp4[prices.size() - 1];
    }
    //滚动数组优化版本，当一个数改成一维数组就是股票四的问题
    int maxProfit_1(vector<int> &prices)
    {
        int dp1, dp2, dp3, dp4;
        dp1 = dp3 = -prices[0];
        dp2 = dp4 = 0;
        for (int price : prices)
        {
            dp1 = max(dp1, -price);
            dp2 = max(dp2, dp1 + price);
            dp3 = max(dp2 - price, dp3);
            dp4 = max(dp4, dp3 + price);
        }
        return dp4;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution12
{
public:
    void reorderList(ListNode *head)
    {
        // vector<ListNode*> temp;
        // ListNode* tem = head;
        // while(tem!=nullptr){
        //     temp.emplace_back(tem);
        //     tem = tem->next;
        // }

        // int left = 0,right = temp.size()-1;
        // while(left<right){
        //     temp[left]->next = temp[right];
        //     temp[right--]->next = temp[++left];
        // }
        //快慢指针寻找链表中点
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *pre = nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr; //断开链表
        //反转链表
        while (curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        //合并链表
        ListNode *tem = head;
        while (pre != nullptr && tem != nullptr)
        {
            ListNode *re_temp = pre->next;
            ListNode *head_temp = tem->next;
            tem->next = pre;
            pre->next = head_temp;
            tem = head_temp;
            pre = re_temp;
        }
        
    }
};