#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;


void Calculate_Totient() {
	vector<bool>pr(N, true);
	vector<int>tot(N);

	for (int i = 2; i < N; i++) {
		for (int j = i * i; j < N; j += i) {
			pr[j] = false;
		}
	}


	// iota(tot.begin(), tot.end(), 0);

	for (int i = 0; i < N; i++) {
		tot[i] = i;
	}


	for (int i = 2; i < N; i++) {
		if (pr[i] == true) {


			//Multiple of this prime ke sath aap (1-1/pr[i]) ko multiply karo.

			for (int j = i; j < N; j += i) {
				//I am 100% sure this j will be divisible be i.
				//Since i is the prime NUmber:

				//THis is what prime Factorisation is all about.
				//i will be prime factor for j.

				tot[j] /= i;
				tot[j] *= (i - 1);
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << i << " " << tot[i] << endl;
	}
}

int main() {
	Calculate_Totient();
}