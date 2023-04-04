/*
 * @Author: xinao_seven_
 * @Date: 2023-04-04 11:56:52
 * @LastEditTime: 2023-04-04 12:02:13
 * @LastEditors: xinao_seven_
 * @Description:
 * @Encoding: utf8
 * @FilePath: \1xingao\cpp\nodp01.cpp
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Soluation
{
    public:
    int res = 0;
    

    void dfs(vector<int> &grid, vector<int> &height,int i,int BagH,int value)
    {
        if(BagH > BagH){ // 超过标准容量
            return;
        }
        res = max(res,value);
        if(i>=grid.size()){return ;}
        
        
        dfs(grid,height,i+1,BagH+height[i],value+grid[i]);
        dfs(grid,height,i+1,BagH,value);
        
    }
    int MaxValue(vector<int> &grid, vector<int> &height,int bagH)
    {

    }
};

int main()
{
    return 0;
}
