#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for (int i = 0; i < n; i++) {
            unordered_set<char> hash_cel, hash_row;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (hash_cel.find(board[i][j]) != hash_cel.end()) {
                    return false;
                } else {
                    hash_cel.insert(board[i][j]);
                }
                if (hash_row.find(board[j][i]) != hash_row.end()) {
                    return false;
                } else {
                    hash_row.insert(board[j][i]);
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                unordered_set<char> hash;
                for (int k = i * 3; k < (i + 1) * 3; k++) {
                    for (int m = j * 3; m < (j + 1) * 3; m++) {
                        if (board[k][m] == '.') {
                            continue;
                        }
                        if (hash.find(board[k][m]) != hash.end()) {
                            return false;
                        } else {
                            hash.insert(board[k][m]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution test;
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
    test.isValidSudoku(board);
    return 0;
}