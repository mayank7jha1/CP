#include<bits/stdc++.h>
using  namespace std;

// class node {
// public:
// 	char data;
// 	node* left;
// 	node* right;

// 	node(char inputdata) {
// 		data = inputdata;
// 		left = NULL;
// 		right = NULL;
// 	}
// };


class node {
public:
	int data;
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

/*
	constant : const and #define
	static :  Initialise one time , isme reflect hone

*/

int pre_i = 0;
node* buildtree3(char *pre, char* in, int s, int e) {
	if (s > e) {
		return NULL;
	}

	node* root = new node(pre[pre_i]);

	int index = -1;//This is for iterating in my inorder array.

	for (int j = s; j <= e; j++) {
		if (in[j] == pre[pre_i]) {
			index = j;
			break;
		}
	}

	pre_i++;

	root->left = buildtree3(pre, in, s, index - 1);
	root->right = buildtree3(pre, in, index + 1, e);

	return root;
}



void LeftView(node* root, int level, int &maxlevel) {
	if (root == NULL) {
		return;
	}

	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}

	LeftView(root->left, level + 1, maxlevel);
	LeftView(root->right, level + 1, maxlevel);
}


void RightView(node* root, int level, int &maxlevel) {
	if (root == NULL) {
		return;
	}

	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}

	RightView(root->right, level + 1, maxlevel);
	RightView(root->left, level + 1, maxlevel);
}


node* insertinbst(node* &root, int x) {
	if (root == NULL) {
		root = new node(x);
		return root;
	}

	if (x < root->data) {
		root->left = insertinbst(root->left, x);
	}

	if (x > root->data) {
		root->right = insertinbst(root->right, x);
	}

	return root;
}

node* buildtree4() {
	int x;
	cin >> x;

	node* root = NULL;

	while (x != -1) {
		root = insertinbst(root, x);
		cin >> x;
	}

	return root;
}

bool search(node* root, int key) {
	if (root == NULL) {
		return false;
	}

	if (root->data == key) {
		return true;
	} else if (root->data < key) {
		search(root->right, key);
	} else {
		search(root->left, key);
	}
}


int main() {
	// node* root = buildtree();
	// Preorder(root);
	// cout << endl;
	// Inorder(root);
	// cout << endl;
	// Postorder(root);
	// cout << endl;
	// cout << sum(root);
	// cout << endl;
	// cout << Countnodes(root) << endl;

	// cout << height(root) << endl;

	// mirror(root);
	// Preorder(root);
	// cout << endl;
	// cout << diameter(root) << endl;

	// pair<int, int>ans = fastdiameter(root);
	// cout << ans.first << " " << ans.second << endl;
	// pair<int, bool>ans1 = isheightbalanced(root);
	// cout << ans1.first << " " << ans1.second << endl;

	// char arr[] = {'x', 'y', 'z', 'p', 'l', 'o', 'm', 'q', '\0'};

	// node* root1 = buildtree2(arr, 0, 7);
	// Preorder(root1);
	// cout << endl;
	// pair<int, bool>ans2 = isheightbalanced(root1);
	// cout << ans2.first << " " << ans2.second << endl;


	// node* root3 = buildtree();
	// Preorder(root3);
	// cout << endl;
	// pair<int, bool>ans3 = isheightbalanced(root3);
	// cout << ans3.first << " " << ans3.second << endl << endl;

	// PrintAllLevel(root3);
	// cout << endl;
	// bfs(root3);


	// char pre[] = {"xyzplms"};
	// char in[] = {"zypxmls"};

	// node* root4 = buildtree3(pre, in, 0, 6);

	// Preorder(root4);
	// cout << endl;
	// Inorder(root4);
	// cout << endl;

	// pair<int, int>p = fastdiameter(root4);
	// cout << p.first << " " << p.second << endl;

	// int x = 0;

	// LeftView(root4, 1, x);
	// x = 0;
	// cout << endl;
	// RightView(root4, 1, x);

	node* root5 = buildtree4();
	Inorder(root5);
	cout << endl;
}
















