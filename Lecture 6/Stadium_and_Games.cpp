#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define TT 1e18

void Solve() {
	//Number of Matches.
	int n;
	cin >> n;

	//This will contain all my potential teams that will play n matches in asc. order
	set<int>st;

	//This is for D. We are putting D as i through this loop.
	for (int i = 0; i < 63; i++) {
		int c = pow(2, i) - 1;

		//We are defining the range for m.
		int s = 0, e = 1e10;

		//Edge Case for Less Computation.
		if (n == c) {
			/*
				This means the total number of matches is equal to c.
				This means you don't have to check for m as i know the answer
				i.e 1. This means m can only have a single value i.e 1.

				And since we have successfully found values of d and m satifying
				the equation where d is in this scenario the value of i and m=1
				this becomes one of the solution hence we will store it.

				//Total number of teams we can calculate now by pow(2,i)*1

				c=2^d-1;
				Total number of teams is equal to= (2^d)*m.
				Total number of teams is equal to= (c+1)*m.
			*/
			st.insert(c + 1);
			continue;
			//You don't have to look for m as there can't be any other value than 1.
			//Also because for a particular d there can be only one value of m.
		}
		//If you have not found the value for m till now you have try to find
		// it in the range of 0----10^10.

		while (s <= e) {
			int equation = 0;
			int mid = (s + e) / 2;
			equation = mid; equation *= (mid - 1); equation /= 2;
			int extra = c;

			//This Equation Gives you total number of matches.
			//It is possible that this overflows.

			/*
				Since we know that the answer or n(being the number of matches) ki value will lie in the range of 1---10^18.

				if(c*mid)==overflow kar raha hai to isko rok do kaise???
				c*mid====max value can only be 10^18.

				How will i check pehle ki overflow hain???

				mid>max(10^18)/c se then it will definedly overflow.

				How i can avoid overflow by saying since the answer for
				c*mid can only be in range upto 10^18 and since we are overshooting that we will make it 10^18 again.

			*/

			if (extra != 0 and mid > (TT / extra)) {
				equation = TT;
			} else {
				equation = extra * mid + equation;
			}

			if (equation == n) {
				//ek answer mil gaya put teams in set and move on.
				if (mid % 2 == 1) {
					st.insert((extra + 1)*mid);
				}
				break;
			}

			if (equation > n) {
				e = mid - 1;
			}
			if (equation < n) {
				s = mid + 1;
			}
		}
	}

	if (st.size() == 0) {
		cout << "-1" << endl;
	} else {
		for (auto x : st) {
			cout << x << endl;
		}
	}
}




int32_t main() {
	Solve();
}


/*
	Total Number of Teams= (2^d)*M.
	c=2^d-1

	c+1=2^d
	Total Number of Teams= (c+1)*M.


	equation=0
	equation=m*(m-1)/2;

	equation 10^21;

	m hain hi nahi?

*/