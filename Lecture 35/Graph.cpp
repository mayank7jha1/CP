#include<bits/stdc++.h>
using namespace std;
const int N = 0;
/*
	Adj. List:
	Nodes and Neighbours
*/

template<typename T>

//N=10^5;

//First Way:
class Graph {
	// pair<char, vector<char>>um[100];
	map<T, list<T>>um;
	// list: Doubly Linked List.

public:

	void addEdge(T x, T y, bool direction) {
		//x ki neighbour me y ko daalo
		//and agar graph undirected hain to y ke neighbour me x ko dalo.

		um[x].push_back(y);

		if (direction == 0) {
			um[y].push_back(x);
		}
	}

	//This is me Printing out the adj. List.
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
	Graph<char>gr;
	int nodes, edges;
	cin >> nodes >> edges;
	int undirected = 0;
	for (int i = 0; i < edges; i++) {
		char ch1, ch2;
		cin >> ch1 >> ch2;
		gr.addEdge(ch1, ch2, 0);
	}

	gr.Print();
}

//direction ------> 1: Directed Graph  0: Undirected Graph
