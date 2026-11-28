class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> arr(n + 2, 0);
        for (auto& e : requests) {
            int start = e[0];
            int end = e[1];
            arr[start] += 1;
            arr[end + 1] -= 1;
        }

        int sum = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            res.push_back(sum);
        }

        sort(res.rbegin(), res.rend());
        
        sort(nums.rbegin(), nums.rend());
       
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total = (total + (1LL * res[i] * nums[i])) % MOD;
        }

        return total % MOD;
    }
};