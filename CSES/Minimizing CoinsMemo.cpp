#include <bits/stdc++.h>
using namespace std;

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


int getMinimalCoinsToReachSumPerm(int sum, vector<int> &coins, vector<int> &memo){
    if(sum == 0){
        return 0;
    }
    
    if(memo[sum] != -1){
        return memo[sum];
    }
    
    //level = sum
    //options = Every coin denomination
    int res = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(sum >= coins[i]){
            int recRes = getMinimalCoinsToReachSumPerm(sum - coins[i], coins, memo);
            if(recRes != INT_MAX){
                res = min(res, 1 + recRes);
            }
        }
    }
    return memo[sum] = res;
}


int main() {
	// your code goes here
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    /*
    vector<vector<int> > memo(n, vector<int>(sum + 1, -1));
    int res = getMinimalCoinsToReachSum(0, sum, coins, memo);
    res != INT_MAX ? cout << res << '\n' : cout << -1 << '\n';
    */
    vector<int> memo(sum + 1, - 1);
    int res = getMinimalCoinsToReachSumPerm(sum, coins, memo);
    res != INT_MAX ? cout << res << '\n' : cout << -1 << '\n';
}
