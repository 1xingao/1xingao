
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

int main()
{
    Solution test;
    vector<vector<int>> t{{{0,5},{1,2}}};
    test.substringXorQueries("101101",t);
    return 0;
}