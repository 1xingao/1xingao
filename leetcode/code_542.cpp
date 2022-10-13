/*
 * @Author: xinao_seven_
 * @Date: 2022-10-04 16:47:47
 * @LastEditTime: 2022-10-04 17:34:09
 * @LastEditors: xinao_seven_
 * @Description: leetvcode_542
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\code_542.cpp
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& mat,int row,int col){
        if(row <0 || row >mat.size() || col <0|| col >mat[0].size()){
            return INT_MAX;
        }
        if(mat[row][col] == 0){
            return 0;
        }
        
        int left = dfs(mat,row,col-1);
        int top  = dfs(mat,row-1,col);
        int right = dfs(mat,row,col+1);
        int Bottom = dfs(mat,row+1,col);
        if(left == 0 || top == 0 || right == 0 || Bottom ==0){
            return 1;
        }
        mat[row][col] =  min(left,min(right,min(top,Bottom)))+1;
        return mat[row][col];
        
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>res(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                res[i][j] = dfs(mat,i,j);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}