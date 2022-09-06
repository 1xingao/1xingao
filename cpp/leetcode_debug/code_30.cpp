/*
 * @Author: xinao_seven_
 * @Date: 2022-09-05 22:49:43
 * @LastEditTime: 2022-09-06 08:26:24
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding method: utf8
 * @FilePath: \1xingao\cpp\code_30.cpp
 * 
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{
    int m = words.size();
    int n = words[0].size();
    int len = m * n;
    int j = 0;
    if (s.size() < len)
    {
        return {};
    }

    map<string, int> hash, tem;
    for (int i = 0; i < words.size(); i++)
    {
        hash[words[i]]++;
    }
    vector<int> res;
    for (int right = len, left = 0; right <= s.size(); left+=n, right+=n)
    {
        string temp = s.substr(left, len);
        int sum = 0;
        for (int i = 0; i < len; i += n)
        {
            if (hash.find(temp.substr(i, n)) == hash.end())
            {
                break;
            }
            tem[temp.substr(i, n)]++;
        }
        if (tem == hash)
        {
            res.push_back(left);
        }
        tem.clear();
    }
    return res;
}
int main(){ 
    vector<string> list{"word","good","best","good"};
    auto res = findSubstring("wordgoodgoodgoodbestword",list);
    for(int i:res){
        cout<< i;
    }
    return 0;
}