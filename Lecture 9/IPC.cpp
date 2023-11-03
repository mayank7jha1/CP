#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
#define int long long

int IPC_Trainers() {

	int Total_Trainers, Days;
	cin >> Total_Trainers >> Days;

	int Arrival_Day[N], Lectures[N], Sadness[N];
	priority_queue<pair<int, int>>pq;

	for (int i = 0; i < Total_Trainers; i++) {
		cin >> Arrival_Day[i] >> Lectures[i] >> Sadness[i];
		pq.push({Sadness[i], i});
	}

	int Lectures_Taken[N] = {0};

	set<int>Available_Days;
	for (int i = 1; i <= Days; i++) {
		Available_Days.insert(i);
	}

	while (!pq.empty()) {

		pair<int, int>x = pq.top();
		pq.pop();

		int Teacher_Index = x.second;

		int Ideal_Start_Date = Arrival_Day[Teacher_Index];
		int Ideal_End_Date = Arrival_Day[Teacher_Index] + Lectures[Teacher_Index] - 1;

		for (int i = Ideal_Start_Date; i <= Ideal_End_Date; i++) {
			auto f = Available_Days.lower_bound(i);

			if (f == Available_Days.end()) {
				break;
			} else {
				Lectures_Taken[Teacher_Index]++;
				Available_Days.erase(f);
			}
		}
	}

	int Total_Sadness = 0;
	for (int i = 0; i < Total_Trainers; i++) {
		Total_Sadness += ((Lectures[i] - Lectures_Taken[i]) * Sadness[i]);
	}

	return Total_Sadness;
}


int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		cout << IPC_Trainers() << endl;
	}
}