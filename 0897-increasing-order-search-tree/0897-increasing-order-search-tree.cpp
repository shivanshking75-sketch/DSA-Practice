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
    TreeNode* ans = new TreeNode(0);
    TreeNode* head = ans;

public:
    TreeNode* increasingBST(TreeNode* root) {
        incOrder(root);
        return head->right;
    }

private:
    void incOrder(TreeNode* root) {
        if (root == nullptr) return;

        incOrder(root->left);

        ans->right = root;
        root->left = nullptr;
        ans = ans->right;

        incOrder(root->right);
    }
};