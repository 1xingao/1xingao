/*
 * @Author: xinao_seven_
 * @Date: 2023-01-18 22:27:24
 * @LastEditTime: 2023-01-28 10:53:49
 * @LastEditors: xinao_seven_
 * @Description:
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\reference.cpp
 *
 */

#include <bits/stdc++.h>
using std::cout;
#define ll long long

void push(const int &num)
{
}

std::unique_ptr<int> fun(std::unique_ptr<int> p)
{
    *p += 1;
    return p;
}

int main()
{
    auto p = std::make_unique<int>(7);
    cout << *p;
    auto q = fun(std::move(p));
    cout << *q;
    {
        int n = 0;
        const int cn = 1;
        push(n);
        push(cn);
        push(2);
    }

    return 0;
}

class Solution
{
public:
    bool strongPasswordCheckerII(std::string password)
    {
        if (password.size() < 8)
        {
            return false;
        }
        std::unordered_set<char> s{'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        bool B = false, S = false, D = false, T = false;
        char last = ' ';
        for (int i = 0; i < password.size(); i++)
        {
            if (islower(password[i]))
            {
                S = true;
            }
            if (isupper(password[i]))
            {
                B = true;
            }
            if (isdigit(password[i]))
            {
                D = true;
            }
            if (s.find(password[i]) != s.end())
            {
                T = true;
            }
            if (last == ' ')
            {
                last = password[i];
            }
            else if (last == password[i])
            {
                return false;
            }
        }
        return S && B && D && T;
    }
};
class Solution {
public:
    int waysToMakeFair(std::vector<int>& nums) {
        // int res = 0;
        // for(int i=0;i<nums.size();i++){
        //     int l = 0,r = 0;
        //     int index = 0;
        //     for(int j=0;j<nums.size();j++){
        //         if(j == i){
        //             continue;
        //         }
        //         if(index%2 == 0){
        //             r += nums[j];
        //         }else{
        //             l += nums[j];
        //         }
        //         index++;
        //     }
        //     if(l ==r){res++;}

        // }
        // return res;
        int res =0 ;
        int left = 0;
        int sum = std::accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            if(i&1){left+=nums[i];}
        }
        int left_begin =0 ; // 奇数当前前缀和
        int right_brgin = 0; // 偶数当前前缀和
        int left_end = left; // 奇数总前缀和
        int right_end = sum-left; // 偶数总前缀和

        for(int i=0;i<nums.size();i++){
            if(i&1){
                if(right_brgin+left_end-left_begin == left_begin+right_end-right_brgin+nums[i])
                {
                    res++;
                }
                left_begin += nums[i];
            }else{
                if(right_brgin+left_end-left_begin == left_begin+right_end-right_brgin-nums[i])
                {
                    res++;
                }
                right_brgin += nums[i];
            }
        }
        return res;
    }
};