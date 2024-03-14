#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>gr[N];

void bfs(int scr, int n, int &ans) {
	vector<int>dis(n, INT_MAX);
	queue<int>q;
	q.push(scr);

	dis[scr] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto next_node : gr[node]) {

			if (dis[next_node] == INT_MAX) {
				q.push(next_node);
				dis[next_node] = dis[node] + 1;

			} else if (dis[next_node] >= dis[node]) {
				int length = dis[node] + dis[next_node] + 1;
				ans = min(ans, length);
			}
		}

	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	int ans = n + 1;

	for (int i = 0; i < n; i++) {
		bfs(i, n, ans);
	}


	if (ans == n + 1) {
		cout << "No Cycle is Present" << endl;
	} else {
		cout << "Shortest Cycle Length is " << ans << endl;
	}

}


