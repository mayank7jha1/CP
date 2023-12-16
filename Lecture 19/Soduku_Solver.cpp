#include<bits/stdc++.h>
using namespace std;
const int N = 0;



class Solution {
	int n = 9;
public:

	bool CanPlace(vector<vector<char>>&matrix, int x, int y, char value) {

		//CHeck 1: We are checking the current row first.
		for (int i = 0; i < n; i++) {
			if (matrix[i][y] == value) {
				return false;
			}
		}

		//Check 2: We are checking the current column.
		for (int i = 0; i < n; i++) {
			if (matrix[x][i] == value) {
				return false;
			}
		}

		//Check 3: We are checking the current subgrid:

		int sx = (x / 3) * 3;
		int sy = (y / 3) * 3;

		for (int i = sx; i < sx + 3; i++) {
			for (int j = sy; j < sy + 3; j++) {
				if (matrix[i][j] == value) {
					return false;
				}
			}
		}

		return true;
	}


	//We are applying our logic row wise.
	bool SodukuSolver(vector<vector<char>>&matrix, int x, int y) {
		//Base Condition:
		if (x == 9) {
			return true;
		}

		/*
			When You have completed a single row, then you have to move to the new row
			and the first column to repeat the process again.
		*/

		if (y == n) {
			return SodukuSolver(matrix, x + 1, 0);
		}

		if (matrix[x][y] != '.') {
			return SodukuSolver(matrix, x, y + 1);
		} else {


			//We are standing at the empty box:

			for (char ch = '1'; ch <= '9'; ch++) {
				if (CanPlace(matrix, x, y, ch) == 1) {
					matrix[x][y] = ch;
					bool SolveRecursion = SodukuSolver(matrix, x, y + 1);
					if (SolveRecursion == true) {
						return true;
					}

				}
			}


			//We are standing at x,y box and we got false as out answer.
			// Hence we will retain its original state.
			matrix[x][y] = '.';
			return false;
		}


	}
	void solveSudoku(vector<vector<char>>& board) {
		bool ans = SodukuSolver(board, 0, 0);
	}
};

int main() {

}