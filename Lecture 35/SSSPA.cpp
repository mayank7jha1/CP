
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

	void bfs(T scr, T des) {
		map<T, int>distance;

		for (auto x : AdjList) {
			distance[x.first] = INT_MAX;
		}

		queue<T>q;
		q.push(scr);
		distance[scr] = 0;

		while (!q.empty()) {
			T node = q.front();
			q.pop();
			for (T nbrs : AdjList[node]) {

				if (distance[nbrs] == INT_MAX) {
					q.push(nbrs);
					distance[nbrs] = distance[node] + 1;
				}
			}
		}

		for (auto x : AdjList) {
			cout << x.first << " -----> " << distance[x.first] << endl;
		}

		// cout << scr << " to  " << des << distance[des] << endl;

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

	gr.bfs('a', 'e');

}