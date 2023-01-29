/*
 * @Author: xinao_seven_
 * @Date: 2023-01-29 12:20:44
 * @LastEditTime: 2023-01-29 12:21:48
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\quick.cpp
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int quick(int b)
{
    auto power = [&](long long a, long long b,const int MOD) {
            long long y = 1;
            for (; b; b >>= 1) {
                if (b & 1) y = y * a % MOD;
                a = a * a % MOD;
            }
            return y;
        };


}



int main()
{
    return 0;
}
