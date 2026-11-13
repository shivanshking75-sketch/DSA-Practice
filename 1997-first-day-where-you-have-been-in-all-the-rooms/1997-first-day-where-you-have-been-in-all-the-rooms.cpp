class Solution {
public:
    static int mod(int x) {
        constexpr int M = 1000000007;
        const int remain = x % M;
        if (remain < 0) return remain + M;
        return remain;
    }

    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        vector<int> dp(nextVisit.size()); dp[0] = 0;

        for (int i = 1; i < nextVisit.size(); i++) { 
            dp[i] = dp[i - 1];

            dp[i] += 1; 

            dp[i] += mod(dp[i - 1] - dp[nextVisit[i - 1]]); 
            dp[i]  = mod(dp[i]);

            dp[i] += 1; 
        }
        
        return mod(dp.back());
    }
};