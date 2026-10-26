/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;

    int fn(TreeNode* root, int& sum) {
        if (!root) {
            return 0;
        }
        sum = root->val + fn(root->left, sum) + fn(root->right, sum);
        mp[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        int sum = 0;
        fn(root, sum);

        int maxi = INT_MIN;
        for (auto& it : mp) {
            int freq = it.second;
            maxi = max(maxi, freq);
        }
        for (auto& it : mp) {
            int freq = it.second;
            if (freq == maxi) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};