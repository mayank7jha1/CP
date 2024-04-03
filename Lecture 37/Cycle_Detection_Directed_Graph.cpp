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

	bool dfs_helper(T scr, map<T, bool>&visited, map<T, bool>&stack) {
		visited[scr] = true;
		stack[scr] = 1;

		for (auto nbr : um[scr]) {

			if ((!visited[nbr] and dfs_helper(nbr, visited, stack) == 1) or stack[nbr] == 1) {

				return true;
			}
		}

		stack[scr] = 0;//Backtracking

		return 0;
	}

	bool dfs() {
		map<T, bool>visited, stack;

		for (auto x : um) {
			if (!visited[x.first]) {
				bool check = dfs_helper(x.first, visited, stack);
				if (check == 1) {
					return 1;
				}
			}
		}

		return 0;
	}



};

int main() {

	Graph<int>gr;
	int nodes, edges;
	cin >> nodes >> edges;

	for (int i = 1; i <= edges; i++) {
		int ch1, ch2;
		cin >> ch1 >> ch2;
		gr.addEdge(ch1, ch2);
	}

	cout << gr.dfs() << endl;

}


