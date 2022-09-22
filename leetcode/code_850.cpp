/*
 * @Author: xinao_seven_
 * @Date: 2022-09-16 18:55:32
 * @LastEditTime: 2022-09-16 19:36:08
 * @LastEditors: xinao_seven_
 * @Description:
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\leetcode_debug\\code_850.cpp
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rectangleArea(vector<vector<int>> &rectangles)
    {
        vector<int> ps;

        //将所有矩形的x坐标加入矩阵
        for (auto &info : rectangles)
        {
            ps.push_back(info[0]);
            ps.push_back(info[2]);
        }
        sort(ps.begin(), ps.end());
        long ans = 0;
        for (int i = 1; i < ps.size(); i++)
        {
            int a = ps[i - 1];
            int b = ps[i];
            if (b - a == 0)
            {
                continue;
            }

            int width = b - a;
            vector<vector<int>> lines;
            for (auto &info : rectangles)
            {
                if (info[0] <= a && info[2] >= b)
                {
                    lines.push_back({info[1], info[3]});
                }
            }
            sort(lines.begin(), lines.end());
            int height = 0, l = -1, r = -1;
            for (auto &cur : lines)
            {
                if (cur[0] > r)
                {
                    height += r - l;
                    l = cur[0];
                    r = cur[1];
                }
                else if (cur[1] > r)
                {
                    r = cur[1];
                }
            }
            height += r - l;
            ans += (height * width);
            ans = ans % 1000000007;
        }

        return ans;
    }
};
