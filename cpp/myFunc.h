/*
 * @Author: xinao_seven_
 * @Date: 2022-09-07 12:48:22
 * @LastEditTime: 2022-09-07 12:51:31
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \1xingao\cpp\myFunc.h
 * 
 */

#pragma once
#include<string>
#include<vector>

const std::vector<std::string> split(const std::string &str, const std::string &pattern)
{
    std::vector<std::string> result;
    std::string::size_type begin, end;

    end = str.find(pattern);
    begin = 0;

    while (end != std::string::npos)
    {
        if (end - begin != 0)
        {
            result.push_back(str.substr(begin, end - begin));
        }
        begin = end + pattern.size();
        end = str.find(pattern, begin);
    }

    if (begin != str.length())
    {
        result.push_back(str.substr(begin));
    }
    return result;
}