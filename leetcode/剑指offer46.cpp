/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……
，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        if(num<10){
            return 1;
        }
        vector<int>nums;
        while(num>0){
            nums.push_back(num%10);
            num/=10;
        }
        
        reverse(nums.begin(),nums.end());
        vector<int> dp(nums.size(),0);
        
        dp[0] = 1;
        if(10<=(nums[0]*10+nums[1])&&(nums[0]*10+nums[1])<26){
            dp[1] =2;
        }else{
            dp[1] = 1;
        }
        
        for(int i=2;i<nums.size();i++){
            if(10<=(nums[i]+nums[i-1]*10)&&(nums[i]+nums[i-1]*10)<26){
                dp[i] = dp[i-1]+dp[i-2];
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[nums.size()-1];
    }
};