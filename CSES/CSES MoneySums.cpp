#include <bits/stdc++.h>
using namespace std;


void getDistinctSumDPOptimised(vector<int> &coins){
    int n = coins.size(), sum = 0;
    for(int i : coins){
        sum += i;
    }
    
    vector<bool> curr(sum + 1, false), next(sum + 1, false);
    
    //base case
    next[0] = true;
    
    for(int idx = n - 1; idx >= 0; idx--){
        for(int j = 0; j <= sum; j++){
            bool inc = false, exc = false;
            //include
            if(j >= coins[idx]){
                inc |= next[j - coins[idx]];
            }
            exc |= next[j];
            curr[j] = inc || exc;
        }
        swap(curr, next);
    }
    
    //print
    int count = 0;
    for(int i = 1; i <= sum; i++){
        if(next[i]){
            count += 1;
        }
    }
    cout << count << '\n';
    for(int i = 1; i <= sum; i++){
        if(next[i]){
            cout << i << " ";
        }
    }
}

void getDistinctSumDP(vector<int> &coins){
    int n = coins.size(), sum = 0;
    for(int i : coins){
        sum += i;
    }
    //dp table
    vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1, false));
    
    //base case
    dp[n][0] = true;
    
    for(int idx = n - 1; idx >= 0; idx--){
        for(int j = 0; j <= sum; j++){
            bool inc = false, exc = false;
            
            //include
            if(j >= coins[idx]){
                inc |= dp[idx + 1][j - coins[idx]];
            }
            
            //exclude
            exc |= dp[idx + 1][j];
            
            dp[idx][j] = inc || exc;
        }
    }
    
    // print all target sums that were possible with the whole array
    // dp[idx][sum] = is it possible to form sum = sum, with elements in range [idx...n - 1]
    int count = 0;
    for(int j = 1; j <= sum; j++){
        if(dp[0][j]){
            count += 1;
        }
    }
    
    cout << count << '\n';
    
    for(int j = 1; j <= sum; j++){
        if(dp[0][j]){
            cout << j << " ";
        }
    }
}

bool getDistinctSum(int idx, int sum, vector<int> &coins, vector<vector<bool> > &memo){
    if(idx >= coins.size()){
        if(sum == 0){
            return true;
        }
        return false;
    }
    
    if(memo[idx][sum]){
        return memo[idx][sum];
    }
    
    bool inc = false, exc = false;
    //include
    if(sum >= coins[idx]){
        inc |= getDistinctSum(idx + 1, sum - coins[idx], coins, memo);
    }
    //exclude
    exc |= getDistinctSum(idx + 1, sum, coins, memo);
    
    return memo[idx][sum] = inc || exc;
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += coins[i];
    }
    // vector<vector<bool> > memo(n, vector<bool>(sum + 1, false)); 
    // for(int i = 1; i <= sum; i++){
    //     bool res = getDistinctSum(0, i, coins, memo);
    // }
    // int count = 0; 
    // for(int j = 1; j <= sum; j++){
    //     if(memo[0][j]){
    //         count += 1;
    //     }
    // }
    // cout << count << '\n';
    // for(int j = 1; j <= sum; j++){
    //     if(memo[0][j]){
    //         cout << j << " ";
    //     }
    // }
    
    // getDistinctSumDP(coins);
    getDistinctSumDPOptimised(coins);
}  
