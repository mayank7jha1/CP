#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int Travel_Cards() {
	int n, a, b, k, f;
	cin >> n >> a >> b >> k >> f;

	/*
		Map:
		Key is a pair and value is a int.
		{Starting Point and Ending Point} :  Cost
	*/
	map<pair<string, string>, int>mp;

	string Prev_dest = "";

	for (int i = 0; i < n; i++) {

		string Starting_Point, Ending_Point;
		cin >> Starting_Point >> Ending_Point;

		//aa-->bb=Rs.a
		//aa-->bb===Rs.b

		// aa-->bb-->rs a+b
		int Journey_Cost = 0;

		if (Prev_dest == Starting_Point) {
			//This Current Trip is a Transhipment.
			Journey_Cost = b;
		} else {
			Journey_Cost = a;
		}

		Prev_dest = Ending_Point;

		if (Starting_Point > Ending_Point) {
			swap(Starting_Point, Ending_Point);
		}

		if (mp.count({Starting_Point, Ending_Point}) == 1) {
			mp[ {Starting_Point, Ending_Point}] += Journey_Cost;
		} else {
			mp[ {Starting_Point, Ending_Point}] = Journey_Cost;
		}
	}

	vector<int>Trip_Cost;//{15,10}

	int Total_Cost = 0;//{25}


	for (auto x : mp) {
		Trip_Cost.push_back(x.second);
		Total_Cost += x.second;
	}

	sort(Trip_Cost.rbegin(), Trip_Cost.rend());

	for (int i = 0; i < k and i < Trip_Cost.size(); i++) {
		if (Trip_Cost[i] >= f) {
			Total_Cost = Total_Cost - Trip_Cost[i] + f;
		} else {
			break;
		}
	}

	return Total_Cost;

}





/*

	Idea is Calculate har trip ka cost and maximum cost vaali
	trip ke badle travel cards lelo.

	Har Trip ka cost kaise nikale??

	Trip ka matlab kya hain idhar:
	a=10,b=5

	aa-->bb:  Journey ka cost is Rs. a
	bb-->aa   Journey ka cost is Rs. b.
	bb-->cc   Journey ka cost is Rs. a


	There are there journeys above.

	Trip: are Only:

	{aa,bb}-->Rs. a+b  and {bb,cc}-->Rs.a

	You have had 6 trip;

	k=4
	f=18

	Trip_Cost: {35,25,19,12,5,7};

	Total_Cost=103-35+18-25+18-19+18:

	Trip_COst[i]<f iske agge ki saari trip ab choti hongi
	kyuki trip cost is sorted.




*/


int32_t main() {
	cout << Travel_Cards() << endl;
}