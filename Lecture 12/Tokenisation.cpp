#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {

	// char ch[] = "My name is Mayank";

	// char* token = strtok(ch, " ");
	// cout << token << endl;

	// // token = strtok(NULL, " ");
	// // cout << token << endl;
	// // token = strtok(NULL, " ");
	// // cout << token << endl;
	// // token = strtok(NULL, " ");
	// // cout << token << endl;

	// while (token != NULL) {
	// 	token = strtok(NULL, " ");
	// 	cout << token << endl;
	// }

	//Mayank is name My;
	// vector<string>;
	string s = "My name is Mayank";

	vector<string>ans;

	//This is for the first time only.
	char* token = strtok((char*)s.c_str(), " ");

	// cout << token << endl;
	//ans.push_back(token);

	while (token != NULL) {
		ans.push_back(token);
		token = strtok(NULL, " ");

	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}