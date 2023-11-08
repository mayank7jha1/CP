#include<bits/stdc++.h>
using namespace std;
const int N = 0;

/*
	Count[0][0]== Character is a and Position is Even.
	Count[0][1]== Character is a and Position is Odd.
	Count[1][0]==Character is b and Position is Even.
	Count[1][1]== Character is b and Position is Odd.

*/

int Count[2][2] = {{0}};

void Count_Good_Substring(string s) {
	int n = s.length();
	int Even = 0, Odd = 0;

	for (int i = 0; i < n; i++) {

		Odd++;
		if (i % 2 == 1) {

			/*
				This is a Odd Index i.e. we are adding character at
				even place.
			*/
			char Ch = s[i];
			int Character_Index = (Ch - 'a');

			Odd += Count[Character_Index][0];
			Count[Character_Index][0]++;
			Even += Count[Character_Index][1];

		} else {

			/*
				This is a Even Index i.e. we are adding character at
				Odd place.
			*/
			char Ch = s[i];
			int Character_Index = (Ch - 'a');

			Odd += Count[Character_Index][1];
			Count[Character_Index][1]++;
			Even += Count[Character_Index][0];



		}
	}

	cout << Even << " " << Odd << endl;

}



int main() {
	string s;
	cin >> s;

	Count_Good_Substring(s);
}


































