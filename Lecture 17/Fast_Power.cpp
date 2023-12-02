#include<iostream>
using  namespace std;


//Log2(n);

int Fast_Power(int x, int y) {

	if (y == 0) {
		return 1;
	}

	int small_part = Fast_Power(x, y / 2);

	if (y % 2 == 1) {
		return x * small_part * small_part;
	}

	return small_part * small_part;
}



int main() {
	int x, y;
	cin >> x >> y;

	cout << Fast_Power(x, y) << endl;
}