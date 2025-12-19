class Solution {
public:

    long long getMaxProfitDP(int k, vector<int> &prices){
        int n = prices.size();
        vector<vector<long long> > curr(3, vector<long long>(k + 1, 0)), next(3, vector<long long>(k + 1, 0));
    
        //base case
        for(int i = 1; i <= 2; i++){
            for(int j = 0; j <= k; j++){
                next[i][j] = -1e18;
            }
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= 2; j++){
                long long transact = -1e18, shortSell = -1e18, sell = -1e18, skip = -1e18;
                for(int l = 0; l <= k; l++){
                    if(l > 0 && j == 0){
                        transact = next[1][l - 1] - prices[i];
                        shortSell = next[2][l - 1] + prices[i];
                    }
                    if(j != 0){
                        if(j == 1){
                            sell = next[0][l] + prices[i];
                        }
                        else{
                            sell = next[0][l] - prices[i];
                        }
                    }
                    skip = next[j][l];

                    curr[j][l] = max(skip, max(sell, max(transact, shortSell)));
                }
            }
            swap(curr, next);
        }
        return next[0][k];
    }

    long long getMaxProfit(int idx, int state, int k, vector<int> &prices, vector<vector<vector<long long> > > &memo){
        if(idx >= prices.size()){
            if(state == 0){
                return 0;
            }
            return -1e18;
        }

        if(memo[idx][state][k] != -1){
            return memo[idx][state][k];
        }

        //levels = each stock price
        //options = transact, short sell, do nothing
        
        // when state = 0, then only you can make a valid transaction
        long long transact = -1e18, shortSell = -1e18, sell = -1e18, skip = -1e18;

        //Start Transaction (Buy or Short sell)
        if(k > 0 && state == 0){
            transact = getMaxProfit(idx + 1, 1, k - 1, prices, memo) - prices[idx];
            shortSell = getMaxProfit(idx + 1, 2, k - 1, prices, memo) + prices[idx];
        }
        
        // Complete transaction (Sell Or Buy back)
        if(state != 0){
            if(state == 1){
                sell = getMaxProfit(idx + 1, 0, k, prices, memo) + prices[idx];
            }
            else{
                sell = getMaxProfit(idx + 1, 0, k, prices, memo) - prices[idx];
            }
        }
        skip = getMaxProfit(idx + 1, state, k, prices, memo);

        return memo[idx][state][k] = max(skip, max(sell, max(transact, shortSell)));
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // vector<vector<vector<long long> > > memo(n, vector<vector<long long> > (3, vector<long long>(k + 1, -1)));
        // return getMaxProfit(0, 0, k, prices, memo);
        return getMaxProfitDP(k, prices);
    }
};
