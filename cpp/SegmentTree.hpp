/*
 * @Author: xinao_seven_
 * @Date: 2022-10-17 20:43:51
 * @LastEditTime: 2022-10-18 11:48:57
 * @LastEditors: xinao_seven_
 * @Description: 线段树板子
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\SegmentTree.h
 *
 */
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegTreeLazyRangeAdd
{
    vector<T> tree, lazy; //线段树和懒惰标记数组

    int n, root, end; //区间长度，根节点编号，区间结尾下标志

    //下放懒惰标记
    void maintain(int cl, int cr, int p)
    {
        int cm = cl + (cr - cl) / 2;
        if (cl != cr && lazy[p])
        {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
            tree[p * 2] += lazy[p] * (cm - cl + 1);
            tree[p * 2 + 1] += lazy[p] * (cr - cm);
            lazy[p] = 0;
        }
    }
    //区间和[l,r]为查询长度，[cl,cr]为当前包含的区间，p为节点编号
    T range_sum(int l, int r, int cl, int cr, int p)
    {
        if (l <= cl && cr <= r)
            return tree[p];
        int m = cl + (cr - cl) / 2;
        T sum = 0;
        maintain(cl, cr, p);
        if (l <= m)
            sum += range_sum(l, r, cl, m, p * 2);
        if (r > m)
            sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
        return sum;
    }
    //区间修改，在一个区间都加上一个值，all！！！！！！！！
    void range_add(int l, int r, T val, int cl, int cr, int p)
    {
        if (l <= cl && cr <= r)
        {
            lazy[p] += val;
            tree[p] += (cr - cl + 1) * val;
            return;
        }
        int m = cl + (cr - cl) / 2;
        maintain(cl, cr, p);
        if (l <= m)
            range_add(l, r, val, cl, m, p * 2);
        if (r > m)
            range_add(l, r, val, m + 1, cr, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    void build(vector<T> &arr, int s, int t, int p)
    {
        if (s == t)
        {
            tree[p] = arr[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(arr, s, m, p * 2);
        build(arr, m + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

public:
    explicit SegTreeLazyRangeAdd<T>(vector<T> &v)
    {
        n = v.size();

        tree = vector<T>(n * 4, 0);
        lazy = vector<T>(n * 4, 0);

        end = n - 1;
        root = 1;
        build(v, 0, end, 1);
    }

    T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

    void range_add(int l, int r, int val) { range_add(l, r, val, 0, end, root); }

    void range_set(int index , int val){range_add(index,index,val-range_sum(index,index));}
};