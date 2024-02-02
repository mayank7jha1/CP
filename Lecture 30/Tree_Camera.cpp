#include<bits/stdc++.h>
using namespace std;
const int N = 0;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

class Solution {
public:
    unordered_map<TreeNode*, bool>um;
    int camera;
    //I Don't think parent ko store karne ki zarurat hain.

    void Solve(TreeNode* root, TreeNode* parent) {
        if (root == NULL) {
            return;
        }

        Solve(root->left, root);
        Solve(root->right, root);

        //Work: When will i Install Camera:
        if ((parent == NULL and um.count(root) == 0) or (um.count(root->left) == 0) or (um.count(root->right) == 0)) {

            um[parent] = true;
            um[root] = true;
            um[root->left] = true;
            um[root->right] = true;
            camera++;
        }
    }


    int minCameraCover(TreeNode * root) {
        camera = 0;
        um.insert({NULL, true});//NULL ka matlab node is visible.

        Solve({root, NULL});
        return camera;
    }
};

