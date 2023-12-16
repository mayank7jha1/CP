#include<bits/stdc++.h>
using namespace std;
const int N = 0;


class Solution {
public:
    int count = 0;
    vector<vector<string>>result;

    bool CanPlace(vector<string>&board, int row, int column) {

        /*
             Check 1: We are going to check the current column first.
             Please Note we are only dealing with the boxes that are previous to
             this box.
         */

        for (int i = row; i >= 0; i--) {
            if (board[i][column] == 'Q') {
                return false;
            }
        }

        //Check 2: Left Diagonal:
        for (int i = row, j = column; i >= 0 and j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }


        //Check 3: Right Diagonal:
        for (int i = row, j = column; i >= 0 and j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void N_Queen(vector<string>&board, int row) {
        //Base Condition:
        if (row == board.size()) {
            result.push_back(board);
            count++;
            return;
        }


        //We Will move to every Viable Position.
        for (int j = 0; j < board.size(); j++) {
            if (CanPlace(board, row, j) == 1) {

                //Put the Queen and Ask Recursion to do the same for the
                //rest of the boxes.
                board[row][j] = 'Q';
                N_Queen(board, row + 1);

                //BackTracking:
                board[row][j] = '.';
            }
        }
    }

    // vector<vector<string>> solveNQueens(int n) {
    //     if (n <= 0) {
    //         return {{}};
    //     }
    //     vector<string>board(n, string(n, '.'));
    //     N_Queen(board, 0);
    //     return result;
    // }

    int totalNQueens(int n) {
        if (n <= 0) {
            return count;
        }
        vector<string>board(n, string(n, '.'));
        N_Queen(board, 0);
        return count;
    }
};



int main() {

}