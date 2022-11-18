/*
 * @Author: xinao_seven_
 * @Date: 2022-11-16 19:54:15
 * @LastEditTime: 2022-11-16 20:03:02
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\378leet.cpp
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // priority_queue<int,vector<int>,greater<int>> q;
        // for(auto &temp:matrix){
        //     for(int i:temp){
        //         q.push(i);
        //     }
        // }
        // for(int i=0;i<k-1;i++){
        //     q.pop();
        // }
        // return q.top();
        // O(n^2)

        int n = matrix.size();
        vector<int> ptrN(n,0);
        vector<int> res(k,0);
        for(int i=0;i<k;i++){
            int fir = matrix[n-1][ptrN[n-1]];
            for(int j=1;j<n;j++){
                if(ptrN[j] >= matrix[0].size()){continue;}
                fir = min(fir,matrix[j][ptrN[j]]);
            }
            for(int j=0;j<n;j++){
                if(ptrN[j] >= matrix[0].size()){continue;}
                if(fir == matrix[j][ptrN[j]]){
                    ptrN[j]++;
                }
            }
            res[i] = fir;
        }
        return res[3];
    }
};


int main()
{
    Solution s;
    vector<vector<int>> test{{1,5,9},{10,11,13},{12,13,15}};
    s.kthSmallest(test,8);
    return 0;
}
