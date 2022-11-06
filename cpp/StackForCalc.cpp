/*
 * @Author: xinao_seven_
 * @Date: 2022-11-05 14:09:18
 * @LastEditTime: 2022-11-05 14:10:20
 * @LastEditors: xinao_seven_
 * @Description:
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\StackForCalc.cpp
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    //计算(1+2)+4
    int calculate(string s)
    {
        int res = 0, i = 0;
        int sign = 1;
        stack<int> sk;
        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                int n = s[i] - '0';
                while (i + 1 < s.size() && isdigit(s[i + 1]))
                {
                    n = n * 10 + (s[i + 1] - '0');
                    i++;
                }
                res = res + sign * n;
            }
            else if (s[i] == '(')
            {
                sk.push(res);
                sk.push(sign);
                res = 0;
                sign = 1;
            }
            else if (s[i] == '+')
            {
                sign = 1;
            }
            else if (s[i] == '-')
            {
                sign = -1;
            }
            else if (s[i] == ')')
            {
                res = res * sk.top();
                sk.pop();
                res = res + sk.top();
                sk.pop();
            }
            i++;
        }
        return res;
    }
    //计算"&(|(f))"，"|(f,f,f,t)"，"!(&(f,t))"
    bool parseBoolExpr(string expression)
    {

        stack<char> sk;
        for (int i = 0; i < expression.size(); i++)
        {
            char c = expression[i];
            if (c != ')' && c != ',')
            {
                sk.push(c);
            }
            else if (c == ')')
            {
                int t = 0, f = 0;
                while (!sk.empty() && sk.top() != '(')
                {
                    if (sk.top() == 'f')
                    {
                        f++;
                    }
                    else
                    {
                        t++;
                    }
                    sk.pop();
                }

                sk.pop();

                if (sk.top() == '&')
                {
                    sk.pop();
                    sk.push(f > 0 ? 'f' : 't');
                }
                else if (sk.top() == '|')
                {
                    sk.pop();
                    sk.push(t > 0 ? 't' : 'f');
                }
                else
                {
                    sk.pop();
                    sk.push(t > 0 ? 'f' : 't');
                }
            }
        }
        return sk.top() == 't';
    }
};