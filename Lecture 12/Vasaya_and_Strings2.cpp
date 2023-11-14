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
			Current_Number_Of_Changes++;
		}

		while (Current_Number_Of_Changes > k and start <= end) {

			if (s[start] != x) {
				Current_Number_Of_Changes--;
			}

			start++;
		}

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