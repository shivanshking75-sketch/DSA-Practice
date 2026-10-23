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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* x=new TreeNode(val);
        TreeNode* y=root;
        if(y==NULL){
            root =x;
        }
        else{
            while(1){
                if(y->val<x->val){
                    if(y->right==NULL){
                        y->right=x;
                        break;
                    }
                    
                    y=y->right;
                }
                else{
                    if(y->left==NULL){
                        y->left=x;
                        break;
                    }
                    
                    y=y->left;
                }
            }
        }
        return root;
    }
};