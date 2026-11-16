class Solution {
public:
    int t[201][201];
    int solve(int i, int k, vector<int>& nums){
        int n = nums.size();

        if(i == n)return 0;
        if(k < 0)return 1e9;

        if(t[i][k] != -1)return t[i][k];

        int maxi = nums[i], sum = 0, ans = INT_MAX;
        for(int j = i; j < n; j++){
            maxi = max(maxi, nums[j]);
            sum += nums[j];
            ans = min(ans, maxi*(j-i+1) - sum + solve(j+1, k-1, nums));
        }

        return t[i][k] = ans;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(t, -1, sizeof(t));
        int ans = INT_MAX, n = nums.size();
        return solve(0, k, nums);

        return ans;
    }
};