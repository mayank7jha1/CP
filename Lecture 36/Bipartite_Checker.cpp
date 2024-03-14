#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>gr[N];

bool dfs_helper(int node, int parent, int color, vector<int>&visited) {
	visited[node] = color;

	for (auto nbr : gr[node]) {

		if (visited[nbr] == 0) {
			bool Check = dfs_helper(nbr, node, 3 - color, visited);
			if (Check == 0) {
				return false;
			}
		} else if (nbr != parent and visited[nbr] == color) {
			return false;
		}
	}

	return true;
}




bool dfs(int n) {
	vector<int>visited(n, 0);
	/*

	visited[node] = 0; This is not visited.
	visited[node] = 1; This is visited and color assigned to this
	node is 1.
	visited[node] = 2;This is also visited and color assigned to this
	node is 2.

	*/
	int color = 1;
	int ans = dfs_helper(0, -1, color, visited);
	return ans;
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

	if (dfs(n) == 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}