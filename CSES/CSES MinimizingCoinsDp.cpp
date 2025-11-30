#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int getMinimalCoinsToReachSumDP(int sum, vector<int> &coins){
    int n = coins.size();
    vector<vector<int> > dp(n, vector<int>(sum + 1, INF));
    
    //base case
    for(int i = 0; i < n; i++){
        dp[i][0] = 0;
    }
    
    for(int idx = n - 1; idx >= 0; idx--){
        for(int j = 1; j <= sum; j++){
            int inc = INF, exc = INF;
            
            if(j >= coins[idx]){
                inc = 1 + dp[idx][j - coins[idx]];
            }
            
            if(idx < n - 1){
                exc = dp[idx + 1][j];
            }
            dp[idx][j] = min(inc, exc);
        }
    }
    return dp[0][sum] != INF ? dp[0][sum] : -1;
}

//do combinations with repetition
int getMinimalCoinsToReachSum(int idx, int sum, vector<int> &coins, vector<vector<int> > &memo){
    //No coins needed to form sum = 0
    if(sum == 0){
        return 0;
    }
    
    //memo check
    if(memo[idx][sum] != -1){
        return memo[idx][sum];
    }
    
    //level = sum
    //options = inc the current coin & stay or exclude the current coin & move to next coin
    /*
    OPTION 1: {idx, sum - coins[idx]} //inc with repetition
    OPTION 2: {idx + 1, sum} // exc
    */
    int inc = INT_MAX, exc = INT_MAX;
    
    //Include in subset when there is space to include.
    if(sum >= coins[idx]){
        int res = getMinimalCoinsToReachSum(idx, sum - coins[idx], coins, memo);
        if(res != INT_MAX){
            inc = 1 + res;
        }
    }
    //Exclude the current coin, move to next denomination only if there is next
    if(idx < coins.size() - 1){
        exc = getMinimalCoinsToReachSum(idx + 1, sum, coins, memo);
    }
    return memo[idx][sum] = min(inc, exc);
}

int main() {
	// your code goes here
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    // vector<vector<int> > memo(n, vector<int>(sum + 1, -1)); 
    // cout << getMinimalCoinsToReachSum(0, sum, coins, memo);
    cout << getMinimalCoinsToReachSumDP(sum, coins) << '\n';
}
