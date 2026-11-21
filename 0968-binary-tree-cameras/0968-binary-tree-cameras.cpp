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

    pair<int, pair<int,bool> > solve(TreeNode*root){
        if(root==nullptr) return {0,{0,true}};

        pair<int, pair<int,bool> > right=solve(root->right);
        pair<int, pair<int,bool> > left=solve(root->left);

        bool covered=true;        
        int hasCamera = 1 + min(left.first,left.second.first) + min(right.first,right.second.first);
        int noCamera  =  left.first + right.first;

        if(left.second.second && right.second.second && (left.second.first+right.second.first)<=noCamera){
            covered=false;
            noCamera=left.second.first+right.second.first;
        }

        if(root->right!=nullptr && left.second.second&& (left.second.first+right.first)<=noCamera) {
            covered=true;
            noCamera=left.second.first+right.first;
        }

        if(root->left!=nullptr && right.second.second&& (left.first+right.second.first)<=noCamera) {
            covered=true;
            noCamera=left.first+right.second.first;
        }

        return {hasCamera,{noCamera,covered}};
    }

    int minCameraCover(TreeNode* root) {
        pair<int,pair<int,bool> >ans=solve(root);

        if(!ans.second.second) return ans.first;
        
        return min(ans.first,ans.second.first);
    }
};