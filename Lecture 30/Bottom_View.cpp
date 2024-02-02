#include<bits/stdc++.h>
using namespace std;
const int N = 0;

vector<int>Bottomview(TreeNode* root) {
	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	map<int, int>mp;
	queue < pair<TreeNode*, int>>q;

	q.push({root, 0});

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		//Idea is we are just printing the first node of every column.
		TreeNode* n = f.first;
		int column = f.second;

		//This will ensure ki aap map ke ander ek column as a key ki values
		//ko update karte jaarahe ho, hence it will ensure ki are printing
		//the last value of a particular column.

		mp[column] = n->val;


		if (n->left != NULL) {
			q.push({n->left, column - 1});
		}
		if (n->right != NULL) {
			q.push({n->right, column + 1});
		}
	}


	for (auto x : mp) {
		ans.push_back(x.second);
	}

	return ans;

}

