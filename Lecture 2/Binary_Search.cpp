#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int target;

//O(n)
bool Linear(int* a, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == target) {
			return true;
		}
	}
	return false;
}


//O(log(n))
bool Binary(int* a, int n) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == target) {
			return true;
		} else if (a[mid] > target) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return false;
}

//Always define the search space first.
//Jab tak search space valid hain tab tak searching ka task perform karo.


/*
	This Function will give me the first index that is greater than or equal to x.
*/
int Lower_Bound(int*a, int n) {
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] >= target) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return ans;
}

/*
	This Function will give me the first index that is greater than x.
*/

int Upper_Bound(int*a, int n) {
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] > target) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;

	int a[n];

	//cout << a << endl;


	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// cout << *(a + 1) << endl;
	// cout << a[1] << endl;

	cin >> target;
	// cout << target << endl;

	bool x = Linear(a, n);
	if (x == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	bool t = Binary(a, n);
	if (t == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	int ans = Lower_Bound(a, n);
	if (ans == -1) {
		cout << n << endl;
	} else {
		cout << ans << endl;
	}

	int ans1 = Upper_Bound(a, n);
	if (ans1 == -1) {
		cout << n << endl;
	} else {
		cout << ans1 << endl;
	}

	// mp.find(x)==mp.end

	// mp.begin()
	// mp.end()


	//STL:
	cout << binary_search(a, a + n, target) << endl;

	cout << lower_bound(a, a + n, target) - a << endl;
	cout << upper_bound(a, a + n, target) - a << endl;


	/*

		Starting Point ka Address:
		Ending Point+1 Ka address dete ho.

		Algortithm Search/Find: Agar element present
		nahi hain to aapka stl ka algorithm return
		karta hain this end+1 ka address.

	*/
}

/*

	Lower Bound Case:
	If there are no element present inside the
	array that are greater than or equal to, to the
	element x than just return the size of the array i.e this will signify
	ki saare element chote hain.


*/




// 6422168
// 6422172


/*
	STL:
		1. Containers: Map,Set,Stack,Queue etc.
		2.Algorithms : Sort,find,count etc.
		3.Functors   :
		4.Iterators  : Every Container has its own Iterators.


		.begin()==First block ka address inside the container
		.end()==last+1 block ka address inside the container.


*/