/*
 * @Author: xinao_seven_
 * @Date: 2023-04-04 11:56:52
 * @LastEditTime: 2023-04-04 16:07:26
 * @LastEditors: xinao_seven_
 * @Description:
 * @Encoding: utf8
 * @FilePath: \1xingao\cpp\nodp01.cpp
 *
 */
#include <iostream>
#include<vector>
using namespace std;
// bool数组用来判断搜索的下一个位置是否可行
// col列，dg对角线，udg反对角线
const int N = 100;

int n;
int sum=0;
bool col[N], dg[N], udg[N];
void dfs(int x) {
    if (x == n) {
        sum++;
        return;
    }
    // 枚举这一行，搜索合法的列
    for (int y = 0; y < n; y++)
        //对于一个矩阵来说，同一条反对角线（左下到右上）上所有点下标之和i+j相同且每条对角线值各不相同为0到2(n-1)
        // 同一对角线上点的下标之差相同记为j-i，且每条对角线值各不相同为值为-(n-1)到n-1，为方便判断将j-i加n变为正数
        // 剪枝(对于不满足要求的点，不再继续往下搜索)  
        if (col[y] == false && dg[y - x + n-1] == false && udg[y + x] == false) {
            //放置
            col[y] = dg[y - x + n-1] = udg[y + x] = true;
            dfs(x + 1);//继续搜索
            // 回溯
            col[y] = dg[y - x + n-1] = udg[y + x] = false;
        }
}

class Solution {
public:
    int count =0 ;
    bool isSet(int n,int row,int col,vector<string> checkbox)
    {
        for(int i=0;i<row;i++){
            if(checkbox[i][col] == 'Q'){
                return false;
            }
        }
        for(int i= row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(checkbox[i][j] == 'Q'){
                return false;
            }
        }
        for(int i= row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(checkbox[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void dfs(int n,int row,vector<string>& checkbox)
    {
        if(row == n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isSet(n,row,i,checkbox)){
                checkbox[row][i] = 'Q';
                dfs(n,row+1,checkbox);
                checkbox[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        
        vector<string> temp(n,string(n,'.'));
        dfs(n,0,temp);
        return count;
    }
};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        col[i] = false;
        dg[i] = false;
        udg[i] = false;
    }
    dfs(0);
    cout << sum <<endl;
    Solution test;
    int res = test.totalNQueens(n);
    cout << res <<endl;
    return 0;
}
