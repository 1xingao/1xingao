/*
 * @Author: xinao_seven_
 * @Date: 2022-09-07 12:35:58
 * @LastEditTime: 2022-09-07 16:45:58
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding method: utf8
 * @FilePath: \1xingao\cpp\leetcode_debug\code_1592.cpp
 * 
 */
#include<bits/stdc++.h>
#include "myFunc.h"
using namespace std;
string_Fun myfun;

class Solution {
public:
    string reorderSpaces(string text) {
        
        vector<string> res = myfun.split(text," ");
        int space = 0;
        for(char c:text){
            if(c==' '){
                space++;
            }
            
        }
        string ret;
        int tianc = space / (res.size()-1);
        for(int i=0;i<res.size();i++){
            ret+=res[i];
            for(int j=0;j<tianc;j++){
                ret+=" ";
                space--;
            }
        }
        if(space!=0){
            while(space!=0){
                ret+=" ";
                space--;
            }
        }
        return ret;
    }
    
};
int main()
{
    Solution test;
    string tes = "  this   is  a sentence ";
    string res = test.reorderSpaces(tes);
    cout<<res<<endl;
    return 0;
}