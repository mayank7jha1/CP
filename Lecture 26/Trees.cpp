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
}





