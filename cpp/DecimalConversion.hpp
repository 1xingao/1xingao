/*
 * @Author: xinao_seven_
 * @Date: 2022-10-28 20:26:14
 * @LastEditTime: 2022-10-28 20:26:14
 * @LastEditors: xinao_seven_
 * @Description: 进制转换
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\zhuanhuan.hpp
 *
 */
#include <bits/stdc++.h>

using namespace std;

class decimalConversion
{
public:
    // 十进制转化为任意进制

    /**
     * @description:
     * @param {int} digital
     * @param {int} r
     * @return {*}
     */
    std::string dtox(int digital, int r)
    {
        string result = "";
        const char s[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
        if (digital == 0)
        {
            return "0";
        }
        while (digital != 0)
        {
            int tmp = digital % r;
            result += s[tmp];
            digital /= r;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
