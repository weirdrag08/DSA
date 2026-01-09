class Solution {
public:

    int getMax(int idx, int time, vector<int> &satisfaction, vector<vector<int> > &memo){
        if(idx >= satisfaction.size()){
            return 0;
        }

        if(memo[idx][time] != -1){
            return memo[idx][time];
        }

        //level = each dish
        //option = prepare dish or discard
        int inc = -1e9, exc = -1e9;
        inc = time * satisfaction[idx] + getMax(idx + 1, time + 1, satisfaction, memo);
        exc = getMax(idx + 1, time, satisfaction, memo);
        return memo[idx][time] = max(inc, exc);
    }

    int getMaxDP(vector<int> &satisfaction){
        int n = satisfaction.size();
        vector<vector<int> > dp(n + 1, vector<int>(n + 2, 0));
        for(int j = 0; j <= n + 1; j++){
            dp[n][j] = 0;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j <= n; j++){
                int inc = -1e9, exc = -1e9;
                inc = (j * satisfaction[i]) + dp[i + 1][j + 1];
                exc = dp[i + 1][j];
                dp[i][j] = max(inc, exc);
            }
        }
        return dp[0][1];
    }

    int getMax1DDP(vector<int> &satisfaction){
        int n = satisfaction.size();
        vector<int> curr(n + 2, 0), next(n + 2, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j <= n; j++){
                int inc = -1e9, exc = -1e9;
                inc = (j * satisfaction[i]) + next[j + 1];
                exc = next[j];
                curr[j] = max(inc, exc);
            }
            swap(curr, next);
        }
        return next[1];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        // vector<vector<int> > memo(n, vector<int>(n + 1, -1));
        // return getMax(0, 1, satisfaction, memo);
        // return getMaxDP(satisfaction);
        return getMax1DDP(satisfaction);
    }
};
