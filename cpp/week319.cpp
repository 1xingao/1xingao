/*
 * @Author: xinao_seven_
 * @Date: 2022-11-13 10:09:59
 * @LastEditTime: 2022-11-15 08:57:04
 * @LastEditors: xinao_seven_
 * @Description:
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\week319.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int getMinSwaps(vector<int> &nums)
    {
        map<int, int> mp;
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        for (int i = 0; i < sortedNums.size(); i++)
            mp[sortedNums[i]] = i; // 记录下标索引

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == sortedNums[i])
                continue;
            swap(nums[i], nums[mp[nums[i]]]); // 交换到nums[i]这个值应该在的位置
            cnt++;
        }
        return cnt;
    }
    int minimumOperations(TreeNode *root)
    {
        std::vector<vector<int>> re;
        std::queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            int n = que.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                temp.push_back(node->val);
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            re.push_back(temp);
        }
        int res = 0;
        for (auto &temp : re)
        {
            res += getMinSwaps(temp);
        }
        return res;
    }
};

class Solution
{
public:
    unordered_set<string> set;
    void expand(string str, int low, int high, auto &set)
    {

        while (low >= 0 && high < str.length() && str[low] == str[high])
        {

            set.insert(str.substr(low, high - low + 1));

            low--, high++;
        }
    }

    void findPalindromicSubstrings(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            expand(str, i, i, set);
            expand(str, i, i + 1, set);
        }
    }
    int find(int start,string s){
        for(int i=start;i<s.size();i++){
            for(int j=1;j<s.size()-i;j++){
                if(set.find(s.substr(i,j))!=set.end()){
                    return i+j;
                }
            }
        }
        return -1;
    }
    int maxPalindromes(string s, int k)
    {
        findPalindromicSubstrings(s);
        int res =0 ;
        for(int i=0;i<s.size();i++){
            if(find(i,s)!=-1){
                i=find(i,s);
                res++;
            }
        }
        return res;

    }
};