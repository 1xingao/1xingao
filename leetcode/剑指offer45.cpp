#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool mucmp(string &s1,string& s2){
        return s1+s2<s2+s1;
    }
    string minNumber(vector<int>& nums) {
        vector<string> res;
        for(int i:nums){
            res.push_back(to_string(i));
        }
        sort(res.begin(),res.end(),mucmp);
        string ret;
        for(char c:res){
            ret+=c;
        }
        return ret;
    }
};