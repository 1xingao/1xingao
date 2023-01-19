/*
 * @Author: xinao_seven_
 * @Date: 2023-01-16 10:13:44
 * @LastEditTime: 2023-01-16 10:32:59
 * @LastEditors: xinao_seven_
 * @Description:
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\code1813.cpp
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
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
    
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        auto words1 = split(sentence1," ");
        auto words2 = split(sentence2," ");
        //  int i = 0, j = 0;
        // while (i < words1.size() && i < words2.size() && words1[i] == words2[i]) {
        //     i++;
        // }
        // while (j < words1.size() - i && j < words2.size() - i && words1[words1.size() - j - 1] == (words2[words2.size() - j - 1])) {
        //     j++;
        // }
        // return i + j == min(words1.size(), words2.size());
        deque<string> str1(words1.begin(),words1.end());
        deque<string> str2(words2.begin(),words2.end());
        while(!str1.empty()&&!str2.empty()){
            if(str1[0] == str2[0]){
                str1.pop_front();
                str2.pop_front();
            }else if(str1[str1.size()-1] == str2[str2.size()-1]){
                str1.pop_back();
                str2.pop_back();
            }else{
                return false;
            }
        }
        return str1.empty() || str2.empty();

        
    }
};

int main()
{
    return 0;
}
