#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

//Undirected Graph.
//Shortest Cycle and Cycle Detection using BFS.

//Adjacency List.
//Array of Vectors.

vector<int>gr[N];

//Node(Single Element)  ------->   Neighbours(Vector)
//     0                           1 5
//     1                           0 2
//     2                           1 3 4
//     3                           2 4
//     4                           2 5 3
//     5                           4 0


void bfs(int scr, int n, int &ans) {
	vector<int>dis(n, INT_MAX);

	//Normal BFS:
	queue<int>q;
	q.push(scr);

	dis[scr] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto next_node : gr[node]) {

			if (dis[next_node] == INT_MAX) {
				//This means that the current node is
				//not visited.
				q.push(next_node);
				dis[next_node] = dis[node] + 1;

			} else if (dis[next_node] >= dis[node]) {//This is a backedge

				//THis current node or next node is
				//already visited.

				//Length Of the Cycle.
				int length = dis[node] + dis[next_node] + 1;

				ans = min(ans, length);
			}
		}

	}
}

// 1---- -5
// 1----2
// 2-- -3
// 3----4
// 4----5


// 1---- > 0
// 2---- > 1
// 5---- > 1
// 3---- > 2
// 4---- > 3



// 4----3   (You are standing at 3.)
// 4----5



int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	//int ans;//Length Of the Shortest Cycle.
	//Can there be a cycle of n+1 length where n is the
	//number of nodes.

	int ans = n + 1;

	//Since I don't Know from where I should call bfs
	//as i don't know which node is part of every cycle
	//and hence WE will use bfs from every node.

	for (int i = 0; i < n; i++) {
		bfs(i, n, ans);
	}


	if (ans == n + 1) {
		cout << "No Cycle is Present" << endl;
	} else {
		cout << "Shortest Cycle Length is " << ans << endl;
	}

}







// parent------ > node:


// node------->parent:


// dis[parent] can never be greater than the distance of node.