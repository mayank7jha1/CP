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
    vector<int>Current_Path;//THis is the current path we are iterating.
    vector<vector<int>>ans;//This has all the desired Paths.
public:

    void AllPath(TreeNode* root, int targetSum) {

        if (root == NULL) {
            return;
        }

        Current_Path.push_back(root->val);

        if (root->val == targetSum and root->left == NULL and root->right == NULL) {

            ans.push_back(Current_Path);

        } else {
            AllPath(root->left, targetSum - root->val);
            AllPath(root->right, targetSum - root->val);
        }

        //Either you have had found a path or you have not found a path.
        Current_Path.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        AllPath(root, targetSum);
        return ans;
    }
};