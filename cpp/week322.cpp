/*
 * @Author: xinao_seven_
 * @Date: 2023-02-12 10:11:16
 * @LastEditTime: 2023-02-24 18:15:14
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \1xingao\cpp\week322.cpp
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

class Solution2 {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<string> res(queries.size());
        for(int i=0;i<queries.size();i++){
            int num1 = queries[i][0]^queries[i][1];
            int A[31] = {0};
            for (int j = 30; j >= 0; j--) A[j] = num1 >> j & 1;
            string temp = "";
            for(int j=0;j<31;j++){
                if(temp==""&&A[j]==0){continue;}
                temp += to_string(A[j]);
            }
            res[i] = temp;
        }
        vector<vector<int>> ans;
        for(int i=0;i<queries.size();i++){
            cout << res[i] <<endl;
            if(s.find(res[i])!=string::npos){
                int n =s.find(res[i]);
                int m =res[i].size();
                
                ans.push_back({n,n+m-1});
            }else{
                ans.push_back({-1,-1});
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int n:nums){
            if(n!=0){
                q.push(n);
            }
        }
        int res = 0;
        while(!q.empty()){
            int temp = q.top();
            q.pop();
            int n = q.size();
            for(int i=0;i<n;i++){
                int t = q.top();
                q.pop();
                t -= temp;
                if(t>0){q.push(t);}
            }
            res++;
        }
        return res;
    }
};
class Solution3 {
public:
    int del(string s,char c){
        int res = 0;
        for(char t:s){
            if(t==c){res++;}
        }
        return res;
    }
    int minimumDeletions(string s) {
        // int b = 0;
        // int dp = 0;
        // for(char c:s){
        //     if(c=='a'){
        //         dp = min(dp+1,b);
        //     }else{
        //         b++;
        //     }
        // }
        // return dp;
        int n = s.size();
        int l =0,r = 0;
        for(char c:s){
            if(c =='a'){l++;}
            else{r++;}
        }
        if(l==n||r==n){return 0;}
        int res = INT_MAX;
        int ren = 0;
        int a = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                res = min(res,l+ren);
                ren++;
            }else{
                l--;
                res = min(res,l+ren);
            }
        }
        return res;
        
    }
};
int main()
{
    Solution3 test;
    
    string s=  "aababbab";
    test.minimumDeletions(s);
    return 0;
}
