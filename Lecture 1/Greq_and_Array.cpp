#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define size 100005
int n, m, k;


int32_t main() {
	cin >> n >> m >> k;

	//Why I Have created array of size n+1 because hum log 1 based indexing lene vaale hain.
	int a[n + 1] = {0};

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int l[size], r[size], d[size];

	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> d[i];
	}

	//Queries ka input lelo: and then i resolve the query range.
	//Konsa Operation aapko kitni bar karna hain.
	int op[size] = {0};

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		op[x] += 1;
		op[y + 1] -= 1;
	}

	for (int i = 1; i <= m; i++) {
		op[i] = op[i - 1] + op[i];
	}

	// 2 1 -1 -2

	// for (int i = 1; i <= m; i++) {
	// 	cout << op[i] << " ";
	// }


	int p[size] = {0};
	/*
		I=== index 1 - 2 par jaana hain and add 1, 2 times.

	*/
	for (int i = 1; i < size; i++) {
		p[l[i]] += (op[i] * d[i]);
		p[r[i] + 1] -= (op[i] * d[i]);
	}

	//cout << "CHeck";
	// for (int i = 0; i <= 50; i++) {
	// 	cout << p[i] << " ";
	// }

	for (int i = 1; i < size; i++) {
		p[i] = p[i - 1] + p[i];
	}

	//Add the p array in my original array.
	for (int i = 1; i <= n; i++) {
		a[i] += p[i];
	}

	//Print the Resulted Array.

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
}



// jaha jaha int keyword hai usko long long ke sath replace kardo.
// main function should always return an integer.
// 64-bit: integer: int 4 byte
// int : 4 byte
// by default jitne bhhi 64 ke int hain unko long long bana do.

