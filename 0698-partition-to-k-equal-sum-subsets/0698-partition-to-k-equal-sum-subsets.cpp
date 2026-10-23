class Solution {
public:
    int n;              
    int subsetValue;   

   
    bool helper(vector<int>& nums, int k, int mask, int currentSum, vector<int>& dp) {
        if (k == 0) {
            return mask == (1 << n) - 1;
        }

        if (currentSum == subsetValue) {
            return helper(nums, k - 1, mask, 0, dp);
        }

        if (dp[mask] != -1) {
            return dp[mask];
        }

        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                continue;
            }

           
            if (currentSum + nums[i] <= subsetValue) {
                int newMask = mask | (1 << i);   
                ans = ans || helper(nums, k, newMask, currentSum + nums[i], dp);
                newMask ^= (1 << i);             
            }
        }

        return dp[mask] = ans;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        subsetValue = sum / k;

        if (sum % k != 0) {
            return false;
        }

        vector<int> dp((1 << n) - 1, -1);   
        return helper(nums, k, 0, 0, dp);
    }
};