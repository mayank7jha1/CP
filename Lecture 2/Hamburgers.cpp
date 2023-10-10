#include<bits/stdc++.h>
using namespace std;
#define int long long
// const int N = 1e12 + 1000;
string recipe;
int nb, ns, nc, pb, ps, pc, r;
// int ===10^9 and long long 10^18

int Hamburger() {
	int s = 0;
	int e = 1e12 + 101;
	int ans = -1;//Max Amount of Hamburger you can make.

	//First Step:Find Out Sb,Ss,Sc.
	int Sb = 0, Ss = 0, Sc = 0;

	for (int i = 0; i < recipe.length(); i++) {
		if (recipe[i] == 'B') {
			Sb++;
		} else if (recipe[i] == 'S') {
			Ss++;
		} else {
			Sc++;
		}
	}

	while (s <= e) {
		int mid = (s + e) / 2;

		int Money_Bread = ((((Sb * mid) - nb) * pb) < 0) ? 0 : (((Sb * mid) - nb) * pb);
		int Money_Sausage = ((((Ss * mid) - ns) * ps) < 0) ? 0 : (((Ss * mid) - ns) * ps);
		int Money_Cheese = ((((Sc * mid) - nc) * pc) < 0) ? 0 : (((Sc * mid) - nc) * pc);

		int Total_Required = Money_Bread + Money_Cheese + Money_Sausage;

		if (Total_Required == r) {
			//Total_Required=100,r=100
			return mid;
		} else if (Total_Required < r) {
			//Total_Required=100,r=200
			s = mid + 1;
			ans = mid;
		} else {
			//Total_Required=100 and r=50;
			e = mid - 1;
		}
	}
	return ans;
}

int32_t main() {

	cin >> recipe;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;

	cout << Hamburger() << endl;

}



