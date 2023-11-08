#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int n;
int *height;
int *left_max, *right_min;

int main() {

	cin >> n;
	height = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	left_max = new int[n + 1];
	right_min = new int[n + 1];

	left_max[0] = INT_MIN;

	for (int i = 1; i <= n; i++) {
		left_max[i] = max(left_max[i - 1], height[i - 1]);
	}

	right_min[n] = INT_MAX;

	for (int i = n - 1; i >= 0; i--) {
		right_min[i] = min(right_min[i + 1], height[i]);
	}

	int partition = 1;

	for (int i = 1; i < n; i++) {
		if (left_max[i] <= right_min[i]) {
			partition++;
		}
	}

	cout << partition << endl;
}