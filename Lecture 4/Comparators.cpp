#include<bits/stdc++.h>
using namespace std;
const int N = 0;




int main() {

	int a[] = {5, 4, 3, 2, 1, 7, 9, 12, 14};
	vector<int>v{5, 4, 3, 2, 1, 7, 9, 12, 14};
	int n = v.size();


	/*
		1.Put Largest Element at the end and Repeat.(Bubble Sort)
		2.Put Smallest at the begining and Repeat. (Selection Sort)
		3.Put the current ball in its desired location.(Insertion Sort)

	*/
	//Bubble Sort:
	//Best Case Time Complexity: O(n)

	for (int i = 0; i < n - 1; i++) {
		bool flag = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}

	//Selection Sort:
	// Best Case Time Complexity: O(n^2)

	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			swap(a[min_idx], a[i]);
		}
	}


	//STL: Algorithm: sort(): Heap Sort,Tim Sort and Insertion Sort.
	//O(nlogn)



	for (auto x : a) {
		cout << x << " ";
	}
}



/*
	1 2 3 4 5
	4 5 1 2 3
	1 2 3 5 4
*/


//Arrays.sort

//Collections.sort