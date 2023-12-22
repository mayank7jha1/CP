#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
const int P = 1000000007;

class Modulus {
public:
//Addition Property of Modulo.
	int Addition(int x, int y) {
		return (x + y) % P;
	}

//Subtraction Property of Modulo.
	int Subtraction(int x, int y) {
		return ((x - y) % P + P) % P;
	}

//Multiplicative Property of Modulo.
	int Multiply(int x, int y) {
		return (x * y) % P;
	}


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

//Division Property of Modulo. (x/y)%P=(x*y^P-2)
	int Division(int x, int y) {
		return Multiply(x, FastPower(y, P - 2));
	}
};

int32_t main() {
	Modulus m;
	int x, y;
	cin >> x >> y;

	cout << m.Addition(x, y) << endl;
	cout << m.Subtraction(x, y) << endl;
	cout << m.Multiply(x, y) << endl;
	cout << m.Division(x, y) << endl;


}

