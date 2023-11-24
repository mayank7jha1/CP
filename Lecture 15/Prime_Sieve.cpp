#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

/*
	Q. You have to Print Prime Numbers from 2 to N.
	~~O(n):
	Actual Time: O(n*log(log(n)));

*/

/*
	prime[i]==1 Means the current number i.e i
	is not a prime number.

*/
// bool Prime[N] = {0};

//Using Bitset
bitset<N>Prime;//N*1 Bits:

/*
	You have 5 buckets and all of the buckets will
	only contain bits.
	BY default all the bits are intialised to 0.
*/

/*
	N*2 bytes: N*2*8=N*16
*/

void Prime_seive(int n) {

	for (int i = 3; i * i <= n; i += 2) {
		if (Prime[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				Prime[j] = 1;
			}
		}
	}

	//cout << 2 << " ";
	for (int i = 101; i <= 200; i += 2) {
		if (Prime[i] == 0) {
			cout << i << " ";
		}
	}
}


int main() {
	int n;
	cin >> n;
	Prime_seive(n);
}