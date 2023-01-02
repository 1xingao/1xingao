/*
 * @Author: xinao_seven_
 * @Date: 2022-10-17 21:06:53
 * @LastEditTime: 2022-12-20 16:58:04
 * @LastEditors: xinao_seven_
 * @Description: 并查集板子
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\Disjoint-set.cpp
 *
 */

// 并查集

#include <bits/stdc++.h>
using namespace std;

class Disjoint_set
{
public:
    vector<int> fa, rank;
    Disjoint_set() : fa(5005), rank(5005) {}
    Disjoint_set(vector<int> &ph)
    {
        int n = fa.size();
        fa = vector<int>(n + 1);
        rank = vector<int>(n + 1);
    }
    // 根据初始化不同需要更改并查集的第一数字起点
    void init(int n, int start)
    {
        for (int i = start; i <= n; i++)
        {
            fa[i] = i;
            rank[i] = 1;
        }
    }
    // 路径压缩
    int find(int x)
    {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }
    // 按秩排序写法
    void merge(int i, int j)
    {
        int x = find(i), y = find(j);

        if (rank[x] <= rank[y])
        {
            fa[x] = y;
        }
        else
        {
            fa[y] = x;
        }
        if (rank[x] == rank[y] && x != y)
        {
            rank[y]++;
        }
    }
};
// 正常写法
int find(vector<int> &fa, int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa, fa[x]));
}

void merge(vector<int> &fa, int i, int j)
{
    int x = find(fa, i), y = find(fa, j);

    fa[x] = y;
}
