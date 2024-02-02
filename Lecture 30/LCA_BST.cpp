/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//O(height): O(log2(n));
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val > p->val and root->val > q->val) {
            //My Answer Lies in the left subtree.
            return lowestCommonAncestor(root->left, p, q);
        }

        if (root->val < p->val and root->val < q->val) {
            //My Answer Lies in the right subtree.
            return lowestCommonAncestor(root->right, p, q);
        }

        //Any Other Scenario : that means root->val>p and root->val<q  or
        //root->val<p and root->val>q

        return root;
    }
};