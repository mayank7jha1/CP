#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define long long

int a[N] = {0};
int n, d;

void Solve() {
	//First Step:
	// I Will check if my answer exists or not (I will put account balance as 0 (min value) when
	// I am visiting the bank)

	int Account_Balance = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			//This is the day I am Going to visit the bank
			//if my Account Balance is Negative.

			if (Account_Balance < 0) {
				Account_Balance = 0;//Making it Min Value Possible.
			}

		} else {
			Account_Balance += a[i];
			if (Account_Balance > d) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}

	//If YOu are Standing at this Line that means there
	//exists an answer now i Have to minimise the trips to bank.

	int Trips = 0;
	Account_Balance = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {

			//This is the day I am Going to visit the bank
			//if my Account Balance is Negative.

			if (Account_Balance < 0) {
				Trips++;
				//I will make the account balance as the
				//maximum possible in order to minimise the
				//trips.
				Account_Balance = d;
			}


		} else {
			Account_Balance += a[i];
			if (Account_Balance > d) {
				/*
					Since My Answer exists for this situation i will not print -1 and make my
					account balance again as the maximum permissable limit i.e. d.
				*/
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