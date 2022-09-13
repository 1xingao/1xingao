/*
 * @Author: xinao_seven_
 * @Date: 2022-09-11 20:11:41
 * @LastEditTime: 2022-09-11 20:33:20
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\leetcode_debug\\code_857.cpp
 * 
 */

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<vector<double>>h ;
        for(int i=0;i<n;i++){
            h.push_back({(double)wage[i]/quality[i],(double)quality[i]});
        }
        sort(h.begin(),h.end(),[&](vector<double>& p1,vector<double>& p2){
            return p1[0] < p2[0];
        });
        double res = 1e9;
        double total = .0;
        priority_queue<double,vector<double>,less<double>> q;
        for(auto temp :h){
            if(q.size() == k){
                total -= q.top();
                q.pop();
            }
            total += temp[1];
            q.push(temp[1]);
            if(q.size() == k){
                res = min(res,total*temp[0]);
            }
        }
        
        return res;
    }
};

int main()
{
    vector<int> qua{10,20,5};
    vector<int> wage{70,50,30};
    int k = 2;
    Solution test1;
    double res = test1.mincostToHireWorkers(qua,wage,k);
    cout << res;
    return 0;
}
