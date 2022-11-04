/*
 * @Author: xinao_seven_
 * @Date: 2022-04-09 13:59:40
 * @LastEditTime: 2022-11-03 18:19:37
 * @LastEditors: xinao_seven_
 * @Descriptine
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\kmp.cpp
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// namespace std;

// kmp算法具体实现
class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    //判断nneedle是否是hay的子串
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
        {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
    //判断重复的子字符串
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0){
            return true;
        }
        int len = s.size();
        int next[s.size()];
        getNext(next,s);
        if(next[len-1]!=0&&len%(len-next[len-1])==0){
            return true;
        }
        return false;
    }
};
class Solution2 {
public:
    void canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2==1){
            return ;
        }
        int target = sum/2;
        vector<int>dp(target+1);
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
            for(int k =0;k<=target;k++){
                cout << dp[k] << " ";
            }
            cout << endl;
        }
        
    }
};
int main()
{
    Solution2 s;
    vector<int> nums = {1,5,11,5};
    s.canPartition(nums);
    return 0;
}