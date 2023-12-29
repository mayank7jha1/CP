#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P = 1e9 + 7;
const int N = 1e5 + 10;
int Fact[N] = {0};


//Time Complexity: O(1)
//Addition Property of Modulo.
int Addition(int x, int y) {
	return (x + y) % P;
}


//Time Complexity: O(1)
//Subtraction Property of Modulo.
int Subtraction(int x, int y) {
	return ((x - y) % P + P) % P;
}


//Time Complexity: O(1)
//Multiplicative Property of Modulo.
int Multiply(int x, int y) {
	return (x * y) % P;
}



//Time Complexity: O(log(n))
//This is Fermat's Little Theoram.

//Fast Power:
int FastPower(int x, int y) {
	int result = 1;

	while (y > 0) {
		if (y % 2 == 1) {
			result = Multiply(x, result);
		}
		y /= 2;
		x = Multiply(x, x);
	}
	return result;
}

/*
	Inverse w.r.t P:
	(y ^ -1) % P = (y ^ P - 2) % P;
*/

int Inverse(int x) {
	return FastPower(x, P - 2);
}


//Time Complexity: O(log(n))
/*
	Division Property of Modulo:
	(x / y) % P = ((x % P) * (y ^ P - 2) % P) % P;

*/

int Division(int x, int y) {
	return Multiply(x, FastPower(y, P - 2));
}


//O(n)
//Calculating Long Factorial:
Calculate_Factorial() {
	Fact[0] = 1;
	for (int i = 1; i < N; i++) {
		Fact[i] = Multiply(Fact[i - 1], i);
	}
}


//O(logn)
int ncr(int n, int r) {
	return Multiply(Multiply(Fact[n], Inverse(Fact[r])), Inverse(Fact[n - r]));
}


int32_t main() {

}



// (b ^ -1) % P == Fermat's Little Theoram: (b^P-2)%P

// (a*b)%P=1 MMI