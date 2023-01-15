/*
 * @Author: xinao_seven_
 * @Date: 2023-01-15 10:27:34
 * @LastEditTime: 2023-01-15 11:13:43
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\week328.cpp
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
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = 0;
        for(int num:nums){
            int temp = 0;
            while(num){
                temp += num%10;
                num /= 10;
            }
            n += temp;
        }
        return abs(n-sum);
    }
};


class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(auto &temp:queries){
            for(int i=temp[0];i<=temp[2];i++){
                for(int j=temp[1];j<=temp[3];j++){
                    mat[i][j]++;
                }
            }
        }
        return mat;
    }
};


class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        vector<int>temp(n*n,0);
        
    }
};