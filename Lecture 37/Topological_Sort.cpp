#include<bits/stdc++.h>
using namespace std;
const int N = 0;

template<typename T>

class Graph {

	map<T, list<T>>um;
public:

	void addEdge(T x, T y) {
		um[x].push_back(y);
		//um[y].push_back(x);
	}

	void dfs_helper(T scr, map<T, bool>&visited, list<T>&elements) {
		visited[scr] = true;

		for (auto nbr : um[scr]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited, elements);
			}
		}

		elements.push_front(scr);
		return;
	}



	void topological_sort_dfs() {
		map<T, bool>visited;
		list<T>elements;

		for (auto x : um) {
			visited[x.first] = false;
		}

		for (auto x : um) {
			T node = x.first;

			if (!visited[node]) {

				dfs_helper(node, visited, elements);
			}
		}

		for (auto x : elements) {
			cout << x << " ";
		}
		cout << endl;
	}


	void topological_sort_bfs() {
		map<T, int>indegree;
		for (auto x : um) {
			indegree[x.first] = 0;
		}

		//Resolving My Indegree:

		for (auto x : um) {

			for (auto nbr : x.second) {
				indegree[nbr]++;
			}
		}

		//Actual BFS

		queue<int>q;
		//We are going to Print those nodes jinki indegree is zero.
		for (auto x : indegree) {
			if (x.second == 0) {
				q.push(x.first);
			}
		}

		while (!q.empty()) {

			T node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbr : um[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}

	void Print() {
		for (pair<T, list<T>> x : um) {
			T node = x.first;
			list<T>nbr = x.second;
			cout << node << " ----> ";
			for (T y : nbr) {
				cout << y << " ";
			}
			cout << endl;
		}
	}

};

int main() {

	Graph<int>gr;
	int nodes, edges;
	cin >> nodes >> edges;

	for (int i = 1; i <= edges; i++) {
		int ch1, ch2;
		cin >> ch1 >> ch2;
		//cout << ch1 << " " << ch2 << endl;
		gr.addEdge(ch1, ch2);
	}

	gr.Print();
	cout << endl;
	gr.topological_sort_dfs();
	gr.topological_sort_bfs();

}


