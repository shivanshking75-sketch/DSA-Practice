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
    TreeNode* find(TreeNode* root, int x){
        if(!root) return NULL;
        if(root->val == x) return root;

        TreeNode* left = find(root->left, x);
        TreeNode* right = find(root->right, x);

        return left ? left : right;
    }

    int count(TreeNode* root){
        if(!root) return 0;
        return count(root->left) + count(root->right) + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* x_node = find(root, x);

        int c1 = count(x_node->left);
        int c2 = count(x_node->right);
        int parent = n - (c1 + c2 + 1);

        return (c1 > n/2 || c2 > n/2 || parent > n/2);
    }
};