/*
 * @Author: xinao_seven_
 * @Date: 2023-02-05 10:30:04
 * @LastEditTime: 2023-02-05 10:33:38
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\week321.cpp
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


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        for(int i:gifts){
            q.push(i);
        }
        while(k--){
            int n = q.top();
            q.pop();
            int temp = int(sqrt(n));
            q.push(temp);
        }
        int res = 0;
        while (!q.empty())
        {
            res += q.top();
            q.pop();
        }
        return res;
        
    }
};
