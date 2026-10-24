class Solution {
public:
    int maxi = 0;

    int pathLen(TreeNode* root, int val){
        if(!root || root->val != val) return 0;

        return 1 + max(
            pathLen(root->left, val),
            pathLen(root->right, val)
        );
    }

    void DFS(TreeNode* root){
        if(!root) return;

        int left = pathLen(root->left, root->val);
        int right = pathLen(root->right, root->val);

        maxi = max(maxi, left + right);

        DFS(root->left);
        DFS(root->right);
    }

    int longestUnivaluePath(TreeNode* root) {
        DFS(root);
        return maxi;
    }
};