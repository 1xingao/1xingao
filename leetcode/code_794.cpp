/*
 * @Author: xinao_seven_
 * @Date: 2022-09-28 20:13:38
 * @LastEditTime: 2022-09-28 20:13:38
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\code_794.cpp
 * 
 */

#include<bits/stdc++.h>

using namespace std;
class Solution2 {
public:
    bool victor(vector<string>& board,char gp)
    {
        
        for (int i=0;i<3;i++){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]&&board[i][1] == gp){
                return true;
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]&&board[1][i] == gp){
                return true;
            }

        }
        if(board[0][0] == board[1][1]&& board[1][1] == board[2][2] && board[2][2] == gp){
            return true;
        }
        if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] == gp){
            return true;
        }
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int x {0},o{0};
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if(board[i][j] == 'X'){
                    x++;
                }
                if(board[i][j] == 'O'){
                    o++;
                }
            }
        }
        if(victor(board,'X') && victor(board,'O')){
            return false;
        }
        if(o>x){return false;}
        if(victor(board,'X') && x-o!=1){return false;}
        if(victor(board,'O') && x != o){return false;}
        return true;
    }
};
