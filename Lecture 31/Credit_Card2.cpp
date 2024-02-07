#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define long long

int a[N] = {0};
int n, d;

void Solve() {

	int Account_Balance = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (Account_Balance < 0) {
				Account_Balance = 0;
			}

		} else {
			Account_Balance += a[i];
			if (Account_Balance > d) {
				cout << "-1" << endl;
				return;
			}
		}
	}

	int Trips = 0;
	Account_Balance = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (Account_Balance < 0) {
				Trips++;
				Account_Balance = d;
			}


		} else {
			Account_Balance += a[i];
			if (Account_Balance > d) {
				Account_Balance = d;
			}
		}
	}

	cout << Trips << endl;
}

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	Solve();
}