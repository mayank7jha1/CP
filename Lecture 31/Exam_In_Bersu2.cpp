#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int a[N] = {0};
int Students_Time[101] = {0};
int n, m;

void Solve() {

	int Total = 0;

	for (int i = 0; i < n; i++) {

		int Extra_Time = Total + a[i] - m;
		int Students_Removed = 0;

		if (Extra_Time > 0) {

			for (int j = 100; j > 0; j--) {

				if (Students_Time[j] > 0) {

					int Current_Max_Element_Contribution = j * Students_Time[j];

					if (Extra_Time <= Current_Max_Element_Contribution) {
						Students_Removed += ((Extra_Time + (j - 1)) / j);
						break;
					}

					Students_Removed += Students_Time[j];
					Extra_Time -= Current_Max_Element_Contribution;

				}
			}

		}

		Students_Time[a[i]]++;
		Total += a[i];

		cout << Students_Removed << " ";

	}
}


int32_t main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	Solve();
}
