#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10, MOD = 1e9 + 7;


int getCoinCombinations2DP(int sum, vector<int> &coins){
    int n = coins.size();
    vector<vector<int> > dp(n, vector<int>(sum + 1, 0));
    
    //base case, only 1 way to achieve sum = 0
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    
    for(int idx = n - 1; idx >= 0; idx--){
        for(int j = 1; j <= sum; j++){
            int inc = 0, exc = 0;
            if(j >= coins[idx]){
                inc = dp[idx][j - coins[idx]];
            }
            if(idx < n - 1){
                exc = dp[idx + 1][j];
            }
            dp[idx][j] = (inc % MOD + exc % MOD) % MOD;
        }
    }
    return dp[0][sum];
}


int getCoinCombinations2Memo(int idx, int sum, vector<int> &coins, vector<vector<int> > &memo){
    if(sum == 0){
        return 1;
    }
    
    if(memo[idx][sum] != -1){
        return memo[idx][sum];
    }
    
    //level = each coin
    //options = include or exclude from subset
    int inc = 0, exc = 0;
    
    //include only when the capacity allows
    if(sum >= coins[idx]){
        inc = getCoinCombinations2Memo(idx, sum - coins[idx], coins, memo);
    }
    //exclude and move next
    if(idx < coins.size() - 1){
        exc = getCoinCombinations2Memo(idx + 1, sum, coins, memo);
    }
    return memo[idx][sum] = (inc % MOD + exc % MOD) % MOD;
}

int main() {
	// your code goes here
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    vector<vector<int> > memo(n, vector<int>(sum + 1, -1));
    cout << getCoinCombinations2Memo(0, sum, coins, memo) << '\n';
    // cout << getCoinCombinations2DP(sum, coins) << '\n';
}
