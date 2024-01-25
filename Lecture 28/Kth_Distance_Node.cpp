#include<bits/stdc++.h>
using namespace std;
const int N = 0;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*>Parent;
    unordered_set<TreeNode*>visited;
public:

    void Ancestor(TreeNode* root, TreeNode* P) {
        if (root == NULL) {
            return;
        }

        Parent[root] = P;
        Ancestor(root->left, root);
        Ancestor(root->right, root);
    }

    void dfs(TreeNode* node, int k, vector<int>&ans) {
        if (node == NULL or visited.count(node) == 1) {
            return;
        }

        visited.insert(node);
        if (k == 0) {
            ans.push_back(node->val);
        }

        //Node ke left and right ke liye.
        dfs(node->left, k - 1, ans);
        dfs(node->right, k - 1, ans);

        //This is for node ka parent.
        dfs(Parent[node], k - 1, ans);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if (root == NULL) {
            return ans;
        }
        Ancestor(root, NULL);
        dfs(target, k, ans);
        return ans;
    }
};



//You will first have to reach the target.