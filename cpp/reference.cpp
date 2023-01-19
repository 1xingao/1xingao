/*
 * @Author: xinao_seven_
 * @Date: 2023-01-18 22:27:24
 * @LastEditTime: 2023-01-19 10:33:11
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


class Solution {
public:
    bool strongPasswordCheckerII(std::string password) {
        if(password.size()<8){return false;}
        std::unordered_set<char> s{'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        bool B=false,S=false,D=false,T = false;
        char last = ' ';
        for(int i=0;i<password.size();i++){
            if(islower(password[i])){S = true;}
            if(isupper(password[i])){B = true;}
            if(isdigit(password[i])){D = true;}
            if(s.find(password[i])!=s.end()){T = true;}
            if(last == ' '){last = password[i];}
            else if(last == password[i]){return false;}
        }
        return S&&B&&D&&T;
    }
};