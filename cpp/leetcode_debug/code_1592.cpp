/*
 * @Author: xinao_seven_
 * @Date: 2022-09-07 12:35:58
 * @LastEditTime: 2022-09-07 12:37:01
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding method: utf8
 * @FilePath: \1xingao\cpp\leetcode_debug\code_1592.cpp
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> res = split(text," ");
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
    const std::vector<std::string> split(const std::string &str, const std::string &pattern)
{
    std::vector<std::string> result;
    std::string::size_type begin, end;

    end = str.find(pattern);
    begin = 0;

    while (end != std::string::npos)
    {
        if (end - begin != 0)
        {
            result.push_back(str.substr(begin, end - begin));
        }
        begin = end + pattern.size();
        end = str.find(pattern, begin);
    }

    if (begin != str.length())
    {
        result.push_back(str.substr(begin));
    }
    return result;
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