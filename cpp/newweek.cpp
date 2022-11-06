/*
 * @Author: xinao_seven_
 * @Date: 2022-11-06 10:28:50
 * @LastEditTime: 2022-11-06 15:32:32
 * @LastEditors: xinao_seven_
 * @Description:
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\newweek.cpp
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

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                res[index++] = nums[i];
            }
        }
        return res;
    }
};

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        ll res = 0LL;
        ll sum = 0;
        for (int i = 0; k < nums.size(); i++, k++)
        {
            unordered_set<int> hash(nums.begin() + i, nums.begin() + i + k);
            if (hash.size() == k - i)
            {
                res = max(res,sum);
                
            }
            
        }
        return res;
    }
};
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        ll res = 0LL;
        map<int, int> hash;
        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            hash[nums[i]]++;
            sum += nums[i];
        }
        // if(hash.size()==k){
        //     res = accumulate(nums.begin(),nums.begin()+k,0);
        // }
        int n = k;
        for (int i = 0; k < nums.size(); i++, k++)
        {

            long long sum = 0;

            if (hash.size() == n)
            {
                res = max(sum, res);
            }

            if (k == nums.size())
            {
                break;
            }
            auto it = hash.find(nums[i]);
            if (it->second == 1)
            {
                hash.erase(it);
            }
            else
            {
                it->second -= 1;
            }
            hash[nums[k]]++;
            sum += nums[k] - nums[i];
        }
        return res;
    }
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();
        priority_queue<int,vector<int>,less<int>> pq_l,pq_r;
        // int l = candidates-1,r = n-candidates;
        // ll res = 0;
        // for(int i=0;i<=l&&i<=n;i++){
        //     pq_l.push(pair<int,int>{costs[i],i});
        // }
        // for(int j=n-1;j>l&&j>=r&&j>=0;j--){
        //     pq_r.push(pair<int,int>{costs[j],j});
        // }

        // while(k--){
        //     if (pq_l.top().first <= pq_r.top().first){
        //         auto p = pq_l.top();
        //         res += p.first;
        //         pq_l.pop();
        //         if (++l <= r){
        //             pq_l.push(pair<int,int>{costs[l],l});
        //         }
                
        //     }else if(pq_l.top().first > pq_r.top().first){
        //         auto p = pq_r.top();
        //         res += p.first;
        //         pq_r.pop();
        //         if (l <= --r){
        //             pq_r.push(pair<int,int>{costs[r],r});
        //         }
        //     }
        // }
        // return res;
        
        int l = 0,r = n-1;
        for(int i=0;i<candidates;i++){
            if(l<=r){
                pq_l.push(costs[l++]);
            }
            if(l <=r){
                pq_r.push(costs[r--]);
            }
        }
        ll res = 0;
        while(k--){
            int leftmin = pq_l.empty()?INT_MAX:pq_l.top();
            int rightmin = pq_r.empty()?INT_MAX:pq_r.top();

            if(leftmin <= rightmin){
                pq_l.pop();
                if (l <=r){
                    pq_l.push(costs[l++]);
                }
            }else{
                pq_r.pop();
                if(l<=r){
                    pq_r.push(costs[r--]);
                }
            }
            res += min(leftmin,rightmin);
        }
        return res;

    }
};