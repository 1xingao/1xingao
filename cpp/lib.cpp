/*
 * @Author: xinao_seven_
 * @Date: 2023-03-30 22:10:45
 * @LastEditTime: 2023-03-30 23:29:19
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \1xingao\cpp\lib.cpp
 * 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
# include<bits/stdc++.h>
using namespace std;

// const int maxn = 10;
// int n, m, ans;
// int vis[maxn][maxn];
// int dx[5] = {0, 0, 1, -1};
// int dy[5] = {1, -1, 0, 0};

// void dfs(int x, int y, int cnt) {

    
//     if (cnt >= ans) return;
//     if (y == m + 1) x++, y = 1;
//     if (x == n + 1) {
//         ans = cnt;
//         return;
//     }
//     if (vis[x][y]) {
//         dfs(x, y + 1, cnt);
//         return;
//     }


//     vis[x][y] = vis[x - 1][y] = vis[x][y - 1] = vis[x][y + 1] = vis[x + 1][y] = 1;
//     dfs(x, y + 1, cnt + 1);
//     vis[x][y] = vis[x - 1][y] = vis[x][y - 1] = vis[x][y + 1] = vis[x + 1][y] = 0;


//     for (int i = 0; i < 4; i++) {

//         int nx = x + dx[i], ny = y + dy[i];


//         if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny]) {
//             vis[nx][ny] = vis[nx - 1][ny] = vis[nx][ny - 1] = vis[nx][ny + 1] = vis[nx + 1][ny] = 1;
//             dfs(x, y + 1, cnt + 1);
//             vis[nx][ny] = vis[nx - 1][ny] = vis[nx][ny - 1] = vis[nx][ny + 1] = vis[nx + 1][ny] = 0;
//         }
//     }
// }



// int main() {
//     while (~scanf("%d%d", &n, &m)) {
//         memset(vis, false, sizeof(vis));
//         ans = n * m;
//         dfs(1, 1, 0);
//         printf("%d\n", ans);
//     }
//     return 0;
// }


class Soluation{
public:
    int res = INT_MAX;
    vector<vector<int>> cnt ;
    vector<vector<int>>  grid ;
    vector<vector<int>>  grid_copy;
    int temp = 0;

    vector<vector<int>> dir{{0,1},{0,-1},{-1,0},{1,0}};
    void dfs(int pos_x,int pos_y)
    {

        if(pos_y == cnt[0].size()){
            pos_x += 1;
            pos_y = 0;
            
        }
        if(pos_x == cnt.size() )
        {
            for(int i=0;i<cnt.size();i++){
                for(int j=0;j<cnt[0].size();j++){
                    if(cnt[i][j] ==0 ){
                        return;
                    }
                }
            }
            res = min(res,temp);
            if(res == temp){
                grid_copy = grid;
            }
            
            return ;
        }
        if(cnt[pos_x][pos_y]>0){
            dfs(pos_x,pos_y+1);
            return ;
        }
        // 放置警卫，四周全部加一监控
        cnt[pos_x][pos_y] += 1;
        for(int i=0;i<4;i++){
            ope(pos_x+dir[i][0],pos_y+dir[i][1],true);
        }
        temp++;
        grid[pos_x][pos_y] = 1;
        // 下一个位置
        dfs(pos_x,pos_y+1);

        //回溯，将之前的警卫取消，四周的也减少
        grid[pos_x][pos_y] = 0;
        cnt[pos_x][pos_y] -= 1;
        for(int i=0;i<4;i++){
            ope(pos_x+dir[i][0],pos_y+dir[i][1],false);
        }
        temp--;

        // 当前位置不放警卫，直接下一个
        dfs(pos_x,pos_y+1);
    }

    // 加减函数
    void ope(int x,int y,bool z)
    {
        if(x>=0&&y>=0&&x<cnt.size()&&y<cnt[0].size())
        {
            cnt[x][y] += z?1:-1;
        }
    }

    //启动函数，初始化cnt
    int lib(int row,int col)
    {
        // cnt 是和你要求的矩阵大小完全相同的
        this->cnt = vector<vector<int>>(row,vector<int>(col,0));
        this->grid = vector<vector<int>>(row,vector<int>(col,0));
        // cout << cnt.size();
        dfs(0,0);
        for(int i=0;i<cnt.size();i++){
                for(int j=0;j<cnt[0].size();j++){
                    cout << grid_copy[i][j] << ",";
                }
                cout <<endl;
            }
        return res;
    }
    
};

int main()
{
    Soluation test;
    int ans = test.lib(5,4);
    cout << ans << endl;
    return 0;
}