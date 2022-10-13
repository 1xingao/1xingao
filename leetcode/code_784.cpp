/*
 * @Author: xinao_seven_
 * @Date: 2022-10-06 21:57:14
 * @LastEditTime: 2022-10-06 22:02:06
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\code_784.cpp
 * 
 */


#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    void dfs(string &s,int start)
    {
        
        res.push_back(s);
        for(int i=start;i<s.size();i++){
            if(!isalpha(s[i])){
                continue;
            }
            char temp = s[i];
            if(s[i]>=97&&s[i] <= 122){
                s[i]-=32;
                dfs(s,start+1);
                s[i] = temp;
            }
            else if(s[i]>=65&&s[i] <= 90){
                s[i]+=32;
                dfs(s,start+1);
                s[i] = temp;
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        dfs(s,0);
        // unordered_set<string> reshash(res.begin(),res.end());
        // res = vector<int>(reshash.begin(),reshash.end());
        return res;
    }
};


int main(){

    Solution test;
    string te = "a1b2";
    
    for(string s:test.letterCasePermutation(te)){
        cout << s;
    }
    return 0;
}