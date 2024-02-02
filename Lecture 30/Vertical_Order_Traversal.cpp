/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>>mp;//This will contain the output.

        //Level Order Traversal : Follow Kar raha hu.
        queue < pair<TreeNode*, pair<int, int>>q;

        q.push({root, {0, 0}});

        while (!q.empty()) {

            auto f = q.front();
            q.pop();
            TreeNode* n = f.first;
            int column = f.second.first;
            int level = f.second.second;

            mp[column][level].insert(n->val);

            if (n->left != NULL) {
                q.push({n->left, {column - 1, level + 1}});
            }

            if (node->right != NULL) {
                q.push({n->right, {column + 1, level + 1}});
            }
        }


        vector<vector<int>>ans;
        for (auto x : mp) {
            vector<int>current;
            //For a single column
            for (auto y : x.second) {
                //y is a pair of level and multiset .
                //vector ke ander bus har level ke multiset ko dalna hain.
                current.insert(current.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(current);
        }

        return ans;
    }
};


