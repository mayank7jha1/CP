#include<bits/stdc++.h>
using namespace std;
const int N = 0;

bool compare(int &x, int &y) {
	if (x > y) {
		return true;
	} else {
		return false;
	}
	//return x > y;
}

int main() {

	int a[] = {5, 4, 3, 2, 1, 7, 9, 12, 14};
	vector<int>v{5, 4, 3, 2, 1, 7, 9, 12, 14};
	int n = v.size();


	sort(a + 0, a + (n - 1) + 1, compare);
	//reverse(a, a + n);


	// sort(a, a + n, [&](int x, int y) {
	// 	if (x > y) {
	// 		return true;
	// 	} else {
	// 		return false;
	// 	}
	// });

	for (auto x : a) {
		cout << x << " ";
	}
}

// string: Dictionary ascii, lexo

//Comparators Ki aapko ki tarah ka comparison chahiye elements ke bich me.
//Inbuilt Comparators:

// less<int>
// greater<int>
// less_equal<int>
// greater_equal<int>

/*

	Let us say you have 2 elements : x,y
	x comes before y.

	greater<int>

	x>y return true else it will return false.

	whenever there is a false it will swap the element.

	y,x;   desc. order me sort.



*/

