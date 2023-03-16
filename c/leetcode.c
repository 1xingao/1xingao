/*
 * @Author: xinao_seven_
 * @Date: 2023-03-10 11:03:58
 * @LastEditTime: 2023-03-16 09:59:07
 * @LastEditors: xinao_seven_
 * @Description:
 * @Encoding: utf8
 * @FilePath: \1xingao\c\leetcode.c
 *
 */
#include <stdio.h>
#include<stdbool.h>
bool isPalindrome(int x)
{
    if (x < 0 || x % 10 == 0 && x != 0)
    {
        return false;
    }
    int size = 0;
    while (x > size)
    {
        size = size * 10 + x % 10;
        x /= 10;
    }
    return x == size || x == size / 10;
}
int main()
{
    int x = 121;
    isPalindrome(x);
    return 0;
}