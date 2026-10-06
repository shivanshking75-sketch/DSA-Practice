class Solution {
public:
    // holdStock 0-> no, !0 -> stock and it's value

    int f(int stockIdx, int holdStock, vector<int>& prices, vector<vector<int>>& memo){
        int n = prices.size();
        if(stockIdx >= n) return 0;

        if(memo[stockIdx][holdStock] != -1) return memo[stockIdx][holdStock];

        int skip = f(stockIdx+1, holdStock, prices, memo);

        int buy = 0, sell = 0;
        if(prices[stockIdx] < prices[holdStock]){
            buy = f(stockIdx + 1, stockIdx, prices, memo);
        }else{
            sell = (prices[stockIdx] - prices[holdStock]) + f(stockIdx+2, stockIdx, prices, memo);
        }

        return memo[stockIdx][holdStock] = max({skip, buy, sell});
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int M = *max_element(prices.begin(), prices.end());

        vector<vector<int>> memo(n, vector<int>(n, -1));

        return f(0, 0, prices, memo);
    }
};