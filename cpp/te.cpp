/*
 * @Author: xinao_seven_
 * @Date: 2024-09-07 22:20:44
 * @LastEditTime: 2024-09-07 22:20:50
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \1xingao\cpp\te.cpp
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        priority_queue<char,vector<char>,greater<char>> q;
        int n = s.size();
        vector<int> cnt;
        for(int i=0;i<n;i++){
            if(s[i] == '*'){
                auto temp = q.top();
                q.pop();
                cnt.push_back(i);
                for (int j = i-1;j>=0;j--){
                    if(s[j] == temp){cnt.push_back(j);break;}
                }
            }
            else{
                q.push(s[i]);
            }
        }
        if (cnt.size() ==0 ){return s;}
        string res = "";
        sort(cnt.begin(),cnt.end());
        int j = 0;
        for(int i=0;i<n;i++){
            if(j<cnt.size() &&cnt[j] == i){
                j++;
                continue;
            }
            res += s[i];
        }
        return res;
    }
};

int main()
{
    Solution s1 ;
    auto remp = s1.clearStars("ee**");
    cout << remp ;
    return 0;
}