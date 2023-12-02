#include<iostream>
using  namespace std;
#define int long long

int n, h, l, r;
int a[20005];

int Sleeping_Schedule(int i, int Walking_Hour) {

	if (i == n) {
		//Maine Saari Sleep karli hain.
		return 0;
	}


	int Op1_Walking_Hour = (Walking_Hour + a[i]) % h;
	int Op2_Walking_Hour = (Walking_Hour + a[i] - 1) % h;

	int ans1 = 0, ans2 = 0;

	if (Op1_Walking_Hour >= l and Op1_Walking_Hour <= r) {
		ans1 = 1;
	}

	if (Op2_Walking_Hour >= l and Op2_Walking_Hour <= r) {
		ans2 = 1;
	}

	//Main ai hour ke baad sone gaya hu tab meri good sleep kitni hain.
	int Op1 = Sleeping_Schedule(i + 1, Op1_Walking_Hour) + ans1;

	//Main ai-1 hour ke baad sone jarraha hu tab meri good sleep kitni hain.
	int Op2 = Sleeping_Schedule(i + 1, Op2_Walking_Hour) + ans2;


	return max(Op1, Op2);
}


int32_t main() {
	cin >> n >> h >> l >> r;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << Sleeping_Schedule(0, 0) << endl;

}



