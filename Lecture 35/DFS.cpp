#include<bits/stdc++.h>
using namespace std;
const int N = 0;
template<typename T>

class Graph {
	map<T, list<T>>AdjList;
public:

	void addEdge(T x, T y, bool direction) {
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);

	}

	void dfs_helper(T scr, map<T, bool>&visited) {
		cout << scr << " ";
		visited[scr] = 1;

		for (auto x : AdjList[scr]) {

			if (!visited[x]) {
				dfs_helper(x, visited);
			}

		}
	}

	void dfs(T scr) {
		map<T, bool>visited;

		for (auto x : AdjList) {
			visited[x.first] = false;
		}

		dfs_helper(scr, visited);
	}

};


int main() {

	Graph<char>gr;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char ch1, ch2;
		cin >> ch1 >> ch2;
		gr.addEdge(ch1, ch2, 0);
	}

	gr.dfs('a');

}