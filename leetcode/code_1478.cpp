/*
 * @Author: xinao_seven_
 * @Date: 2022-09-30 21:47:44
 * @LastEditTime: 2022-09-30 21:50:01
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\code_1478.cpp
 * 
 */
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        unordered_map<string,int> hash;
        for(string &name:names){
            string tmp = name;
            while(hash.find(name) != hash.end()){
                name = tmp;
                name +="(";
                name +=to_string(++hash[tmp]);
                name += ")";
            }
            res.push_back(name);
            hash[name]++;
        }
        return res;
    }
};
int main()
{
    Solution test;
    vector<string> names{"onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"};
    test.getFolderNames(names);
    return 0;
}