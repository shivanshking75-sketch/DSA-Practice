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
    bool isFlippedOrNot(TreeNode* L, TreeNode* R){
         if (!L && !R)
            return true;

        if (!L || !R)
            return false;

        return L->val == R->val;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        stack<pair<TreeNode*,TreeNode*>>st;
        st.push({root1,root2});
        while(!st.empty()){
        auto [L,R] = st.top();
        st.pop();  

        if(!L && !R) continue;
        if(!L || !R) return false;
        if(L->val != R->val) return false;
           
            bool noFlip =
                isFlippedOrNot(L->left, R->left) &&
                isFlippedOrNot(L->right, R->right);
            bool flip =
                isFlippedOrNot(L->left, R->right) &&
                isFlippedOrNot(L->right, R->left);

            if (!noFlip && !flip)
                return false;

            if (noFlip) {
                st.push({L->left, R->left});
                st.push({L->right, R->right});
            }

            if (flip) {
                st.push({L->left, R->right});
                st.push({L->right, R->left});
            }
        }
    return true;
    }
};