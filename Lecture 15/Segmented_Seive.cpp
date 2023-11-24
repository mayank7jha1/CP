#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define int long long
bitset<N>P;
vector<int>Primes;

//bool Segmented_Prime[N] = {0};

/*
	If Segmented_Prime[i]=1 it means it is not
	as prime number.

*/

void Prime_seive() {
	for (int i = 3; i * i <= N; i += 2) {
		if (P[i] == 0) {
			for (int j = i * i; j <= N; j += i) {
				P[j] = 1;
			}
		}
	}

	Primes.push_back(2);
	for (int i = 3; i <= N; i += 2) {
		if (P[i] == 0) {
			Primes.push_back(i);
		}
	}
}


void Segmented_Sieve(int a, int b) {
	int p1[b - a + 1] = {0};
	//p1[i]=1 iska matlab ye i not prime hain.(Is segment me)


	//Iterate over your primes array and cut one by one all the multiples of
	//the primes[i].

	for (int i = 0; Primes[i]*Primes[i] <= b; i++) {
		//Find the first multiple of this prime number in the range a->b.
		int start = ((a / Primes[i]) * Primes[i]);

		if (start < a) {
			start += Primes[i];
		}
		for (int j = start; j <= b; j += Primes[i]) {
			p1[j - a] = 1;
		}

		//Check for the overlap:
		if (start == Primes[i]) {
			p1[start - a] = 0;
		}
	}

	for (int j = a; j <= b; j++) {
		if (p1[j - a] == 0) {
			cout << j << endl;
		}
	}
}



int32_t main() {
	Prime_seive();

	// for (auto x : Primes) {
	// 	cout << x << " ";
	// }
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			a++;
		}

		Segmented_Sieve(a, b);
		cout << endl;
	}

}