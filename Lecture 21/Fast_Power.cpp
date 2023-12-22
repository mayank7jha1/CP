#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int P = 5;

//Basic Iterative Way: O(b)

int Power(int a, int b) {
	int ans = 1;
	for (int i = 1; i <= b; i++) {
		ans *= a;
	}
	return ans;
}

//Basic Recursive Way: O(b)

int Power1(int a, int b) {
	if (b == 0) {
		return 1;
	}
	int ans = a * Power(a, b - 1);
	return ans;
}

//Fast Power Calculation: O(log(b));

int Fast_Power(int a, int b) {

	if (b == 0) {
		return 1;
	}

	int small_ans = Fast_Power(a, b / 2);

	if (b % 2 == 1) {
		return ((a % P) * (small_ans % P) * (small_ans % P) % P);
	}

	return ((small_ans % P) * (small_ans % P) % P);
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << Power(a, b) << endl;
	cout << Power1(a, b) << endl;
	cout << Fast_Power(a, b) << endl;
}