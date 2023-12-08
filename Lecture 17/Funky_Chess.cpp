#include<bits/stdc++.h>
using namespace std;
const int N = 10;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

int n;
int grid[10][10] = {0};
int Total_Boxes_Where_Knight_Can_Travel = 0;
int ans = -1;//Max Number of Boxes where the knight is able to travel in a single path.


void Input_Grid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == 1) {
				Total_Boxes_Where_Knight_Can_Travel++;
			}
		}
	}
}


void Knight(int x, int y, int count) {

	ans = max(count, ans);


	for (int i = 0; i < 8; i++) {
		int x_new_Co_ordinate = x + dx[i];
		int y_new_Co_ordinate = y + dy[i];

		if (x_new_Co_ordinate >= 0 and x_new_Co_ordinate<N and y_new_Co_ordinate >= 0
		        and y_new_Co_ordinate < N and grid[x_new_Co_ordinate][y_new_Co_ordinate] == 1) {

			grid[x_new_Co_ordinate][y_new_Co_ordinate] = 0;
			Knight(x_new_Co_ordinate, y_new_Co_ordinate, count + 1);

			//Backtracking
			grid[x_new_Co_ordinate][y_new_Co_ordinate] = 1;

		}
	}
}




int main() {
	cin >> n;
	Input_Grid();


	grid[0][0] = 0;
	//Count=Number of boxes where the knight was able to travel in current path.
	//Count will be initialised with 1.


	Knight(0, 0, 1);

	cout << Total_Boxes_Where_Knight_Can_Travel - ans << endl;
}