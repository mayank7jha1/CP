#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Count: Current path me kitne steps lag chuke hain irrespective of where you are.
//ans and ans2: Min Steps kitne hain only if you have reached the destination.

int ans = INT_MAX;
int ans2 = INT_MAX;
int target;

void Solve(int a, int b, int count) {

	if (a > target or b > target) {
		return;
	}


	if (a == target or b == target) {
		ans = min(ans, count);
		return;
	}

	Solve(a + b, b, count + 1);
	Solve(a, a + b, count + 1);

	return;
}

void Function(int a, int b, int count) {

	if (a == 1 and b == 1) {
		ans2 = min(ans2, count);
		return;
	}


	if (a - b > 0) {
		Function(a - b, b, count + 1);
	}

	if (b - a > 0) {
		Function(a, b - a, count + 1);
	}
	return;
}


void Pair() {

	if (target == 1) {
		ans = 0;
		return;
	}

	//Target: Kaise form hota hain.

	for (int i = 1; i < target; i++) {
		Function(i, target - i, 1);
	}
}

int main() {

	cin >> target;
	int count = 0;

	Solve(1, 1, count);
	cout << ans << endl;

	Pair();
	cout << ans2 << endl;


}