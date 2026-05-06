class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(), vector<int>(2, -1));
        return rec(prices, 0, false, memo);
    }

    private:
    int rec(vector<int>& prices, int i, bool bought, vector<vector<int>>& memo) {
        if (i == prices.size()) {
            return 0;
        }
        if (memo[i][bought] != -1) return memo[i][bought];
        int res = rec(prices, i + 1, bought, memo);
        if (bought) {
            res = max(res, prices[i] + rec(prices, i + 1, false, memo));
        } else {
            res = max(res, -prices[i] + rec(prices, i + 1, true, memo));
        }
        return memo[i][bought] = res;
    }
};