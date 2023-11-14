#include<bits/stdc++.h>
using namespace std;
const int N = 0;
string s;
int k;

int Solve(char x) {

	int start = 0;
	int end;
	int maximum_substring_length = 0;
	int Current_Number_Of_Changes = 0;

	for (end = 0; end < s.length(); end++) {
		if (s[end] != x) {
			/*
				This is the character that you have to change that means
				you will exhaust a value of k as you will assume that in this
				current window you will make this change.
			*/
			Current_Number_Of_Changes++;
		}

		//THis is when there are more changes inside the window than that is required.
		//So you are shrinking the window as to make only k number of changes.
		while (Current_Number_Of_Changes > k and start <= end) {

			if (s[start] != x) {
				//THis is the character that i have assumed to change inside this
				//current window and hence i will move my window ahead of it in order
				//to make required number of changes.
				Current_Number_Of_Changes--;

				//Since we will move ahead from this point so current number of changes
				// reduces.
			}

			start++;
		}

		//YOu are currently standing at a window that has desired number of changes
		//i.e. <=k.

		//Just calculate the length.
		int Current_Window_Length = end - start + 1;

		maximum_substring_length = max(maximum_substring_length, Current_Window_Length);
	}

	return maximum_substring_length;
}


int main() {
	int n;
	cin >> n >> k;
	cin >> s;

	// You want to change character b->a.
	int Option1 = Solve('a');

	// You want to change character b->a.
	int Option2 = Solve('b');

	cout << max(Option1, Option2) << endl;
}