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

	void bfs(T scr) {
		map<T, bool>visited;

		/*
			AdjList me Har ek Node par jaao and unko visited
			map me false karna hain.

			node -------> neighbour

		*/

		for (auto x : AdjList) {
			visited[x.first] = false;
		}

		queue<T>q;
		q.push(scr);
		visited[scr] = 1;

		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();

			//AdjList[a]------> All the neighbours
			for (T nbrs : AdjList[node]) {

				if (!visited[nbrs]) {
					q.push(nbrs);
					visited[nbrs] = 1;
				}
			}
		}
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

	gr.bfs('a');

}