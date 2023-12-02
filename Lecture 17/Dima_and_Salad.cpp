#include<iostream>
using  namespace std;
#define int long long

int *taste, *calorie;
int n, k;

int Dima_and_Salad(int i, int sum) {

	if (i == n) {
		if (sum == 0) {
			return 0;
		} else {
			//This Path can never become my answer.
			//option 2= 10544;

			return -1e12;
		}
	}

	//If i had choosen the current ith fruit what will be
	//my taste.
	int Option1 = taste[i] +
	              Dima_and_Salad(i + 1, sum + taste[i] - k * calorie[i]);

	//If i had not choosen the current ith fruit what will be
	//my taste.
	int Option2 = 0 + Dima_and_Salad(i + 1, sum);

	return max(Option1, Option2);

}

int32_t main() {
	cin >> n >> k;

	taste = new int[n];
	calorie = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	int ans = Dima_and_Salad(0, 0);

	if (ans <= 0) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}

}