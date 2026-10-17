class Solution {
public:
    int solve(int idx, int tar, vector<int>& nums,map<pair<int,int>,int>& dp)
    {
        if(idx == -1)
        {
            return tar == 0;
        }

        if(dp.find({idx,tar}) != dp.end())
        {
            return dp[{idx,tar}];
        }

        //nums[idx]
        int first = solve(idx-1,tar-nums[idx],nums,dp);
        //-nums[idx]
        int second = solve(idx-1,tar+nums[idx],nums,dp);

        return dp[{idx,tar}] = first + second;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int,int>,int>dp;

        return solve(n-1,target,nums,dp);
    }
 };