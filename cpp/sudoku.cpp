#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    
    bool isValid(int row,int col,char c,vector<vector<char>> board)
    {
        for(int i=0;i<9;i++){
            if(c == board[row][i]){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(c == board[i][col]){
                return false;
            }
        }
        int startrow = (row/3)*3;
        int startcol = (col/3)*3;
        for(int i=startrow;i<startrow+3;i++){
            for(int j = startcol;j<startcol+3;j++){
                if(c == board[i][j]){
                return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board)
    {
        for (int i = 0;i < 9; i++){
            for (int j = 0;j < 9;j++){
                if(board[i][j] != '.'){
                    continue;
                }
                for (char c = '1';c <= '9';c++){

                    if(isValid(i,j,c,board)){
                        board[i][j] = c;
                        bool flag = dfs(board);
                        if(flag){
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};
void solveSudoku(vector<vector<char>>& board) {
    Solution s;
    s.solveSudoku(board);
}
int main()
{
    //vector<char>{'.','.','.','.','.','.','.','.','.'}
    vector<vector<char>> board{
        vector<char>{'5','3','.','.','7','.','.','.','.'},
        vector<char>{'6','.','.','1','9','5','.','.','.'},
        vector<char>{'.','9','8','.','.','.','.','6','.'},
        vector<char>{'8','.','.','.','6','.','.','.','3'},
        vector<char>{'4','.','.','8','.','3','.','.','1'},
        vector<char>{'7','.','.','.','2','.','.','.','6'},
        vector<char>{'.','6','.','.','.','.','2','8','.'},
        vector<char>{'.','.','.','4','1','9','.','.','5'},
        vector<char>{'.','.','.','.','8','.','.','7','9'}
    };
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<'.';
        }
        cout<<endl;
    }
    cout << "-----------------------------------"<<endl;
    cout << "soluation:"<<endl;
    Solution sol;
    sol.solveSudoku(board);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<'.';
        }
        cout<<endl;
    }
    return 0;
}