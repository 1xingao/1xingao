/*
 * @Author: xinao_seven_
 * @Date: 2023-05-05 20:56:42
 * @LastEditTime: 2023-05-11 16:57:37
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \1xingao\cpp\formation.cpp
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution {
public:
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++){
            int c = s.find(check(i));
            if(c==-1){
                return false;
            }
        }
        return true;
    }
    string check(int n)
    {
        string temp ;
        
        while(n){
            temp+=to_string(n%2);
            n/=2;
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};


int main()
{
    Solution test;
    test.queryString("011",4);
    
    return 0;
}

