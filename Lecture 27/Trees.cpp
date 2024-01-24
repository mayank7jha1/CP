#include<bits/stdc++.h>
using  namespace std;

class node {
public:
	char data;
	node* left;
	node* right;

	node(char inputdata) {
		data = inputdata;
		left = NULL;
		right = NULL;
	}
};

//Preorder Traversal and NULL === 0
node* buildtree() {
	char x;
	cin >> x;
	if (x == '0') {
		return NULL;
	} else {
		node* root = new node(x);
		(*root).left = buildtree();
		root->right = buildtree();
		return root;
	}
}

void Preorder(node* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(node* root) {
	if (root == NULL) {
		return;
	}

	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

void Postorder(node* root) {
	if (root == NULL) {
		return;
	}

	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}


//PostOrder Traversal
int sum(node* root) {
	if (root == NULL) {
		return 0;
	}

	int x_left = sum(root->left);
	int x_right = sum(root->right);

	int ans = x_left + x_right + (root->data - 'a');
	return ans;
}


int Countnodes(node* root) {
	if (root == NULL) {
		return 0;
	}

	int x_left = Countnodes(root->left);
	int x_right = Countnodes(root->right);

	int ans = x_left + x_right + 1;
	return ans;
}


//O(n)
int height(node* root) {
	if (root == NULL) {
		return 0;
	}
	int left_subtree_height = height(root->left);
	int right_subtree_height = height(root->right);

	int ans = max(left_subtree_height, right_subtree_height) + 1;
	return ans;

}


void mirror(node* &root) {
	if (root == NULL) {
		return;
	}

	swap(root->left, root->right);
	mirror(root->left);
	mirror(root->right);
}


//O(n^2)
int diameter(node* root) {
	if (root == NULL) {
		return 0;
	}

	int Op1 = diameter(root->left);
	int Op2 = diameter(root->right);

	int Op3 = height(root->left) + height(root->right);

	return max({Op1, Op2, Op3});
}

//pair<height,diameter>
//O(n)
pair<int, int>fastdiameter(node* root) {
	pair<int, int>ans;

	if (root == NULL) {
		ans.first = 0;
		ans.second = 0;
		return ans;
	}

	pair<int, int>left_subtree = fastdiameter(root->left);
	pair<int, int>right_subtree = fastdiameter(root->right);


	ans.first = max(left_subtree.first, right_subtree.first) + 1;

	int Op1 = left_subtree.second;
	int Op2 = right_subtree.second;
	int Op3 = left_subtree.first + right_subtree.first;

	ans.second = max({Op1, Op2, Op3});
	return ans;
}

//pair<height,isbalanced>
pair<int, bool>isheightbalanced(node* root) {
	pair<int, bool>ans;

	if (root == NULL) {
		ans.first = 0;
		ans.second = 1;
		return ans;
	}

	pair<int, bool>left_subtree = isheightbalanced(root->left);
	pair<int, bool>right_subtree = isheightbalanced(root->right);


	ans.first = max(left_subtree.first, right_subtree.first) + 1;

	bool Op1 = left_subtree.second;
	bool Op2 = right_subtree.second;
	int Op3 = abs(left_subtree.first - right_subtree.first);

	if (Op1 == 1 and Op2 == 1 and Op3 <= 1) {
		ans.second = 1;
	} else {
		ans.second = 0;
	}

	return ans;
}

//Creating a Height Balanced Tree from Array
node* buildtree2(char *a, int s, int e) {
	if (s > e) {
		return NULL;
	}

	int mid = (s + e) / 2;
	node *root = new node(a[mid]);
	root->left = buildtree2(a, s, mid - 1);
	root->right = buildtree2(a, mid + 1, e);

	return root;
}


void PrintKthLevel(node* root, int k) {

	if (root == NULL) {
		return;
	}

	if (k == 1) {
		cout << root->data << " ";
		return;
	}

	PrintKthLevel(root->left, k - 1);
	PrintKthLevel(root->right, k - 1);

}

//O(n^2):
void PrintAllLevel(node* root) {
	int H = height(root);
	for (int i = 1; i <= H; i++) {
		PrintKthLevel(root, i);
		cout << endl;
	}
}

//O(n);

void bfs(node* root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);


	while (!q.empty()) {
		node* first = q.front();
		if (first == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << first->data << " ";
			q.pop();
			if (first->left != NULL) {
				q.push(first->left);
			}
			if (first->right != NULL) {
				q.push(first->right);
			}
		}
	}
}


int main() {
	node* root = buildtree();
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;
	cout << sum(root);
	cout << endl;
	cout << Countnodes(root) << endl;

	cout << height(root) << endl;

	mirror(root);
	Preorder(root);
	cout << endl;
	cout << diameter(root) << endl;

	pair<int, int>ans = fastdiameter(root);
	cout << ans.first << " " << ans.second << endl;
	pair<int, bool>ans1 = isheightbalanced(root);
	cout << ans1.first << " " << ans1.second << endl;

	char arr[] = {'x', 'y', 'z', 'p', 'l', 'o', 'm', 'q', '\0'};

	node* root1 = buildtree2(arr, 0, 7);
	Preorder(root1);
	cout << endl;
	pair<int, bool>ans2 = isheightbalanced(root1);
	cout << ans2.first << " " << ans2.second << endl;


	node* root3 = buildtree();
	Preorder(root3);
	cout << endl;
	pair<int, bool>ans3 = isheightbalanced(root3);
	cout << ans3.first << " " << ans3.second << endl << endl;

	PrintAllLevel(root3);
	cout << endl;
	bfs(root3);

}

















