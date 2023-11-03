#include<bits/stdc++.h>
using namespace std;
#include<vector>
const int N = 0;

int main() {

	vector<int>v = {1, 2, 3, 4, 5};
	vector<int>p = v;

	map<int, int>mp;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	int a[] = {1, 2, 3, 4, 5};
	cout << a << endl;


	//cout << v.begin() << endl;
	for (vector<int>:: iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it) << " ";
	}


	cout << endl;

	/*
		For every element that is inside this vector v , it is
		going to be represented by x.
		So x ka data type would jo har ek element of vector ka hain.
	*/

	for (int x : v) {
		cout << x << " ";
	}

	for (int i = 0; i < 5; i++) {
		mp.insert({i, i + 1});
	}
	cout << endl << endl;;

	for (map<int, int>:: iterator it = mp.begin(); it != mp.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}

	cout << endl;
	for (pair<int, int> x : mp) {
		cout << x.first << " " << x.second << endl;
	}




}