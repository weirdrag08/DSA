#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int getArrangements(int level, int k, int n, vector<int> &memo){
    if(level > n){
        return 0;
    }
    if(level == n){
        return 1;
    }
    
    if(memo[level] != -1){
        return memo[level];
    }
    
    //level = position
    //options = red or white flower
    int count = 0;
    count = (count % MOD + getArrangements(level + 1, k, n, memo) % MOD) % MOD;
    if(level + k <= n){
        count = (count % MOD +  getArrangements(level + k, k, n, memo) % MOD) % MOD;
    }
    return memo[level] = count;
}

//*********Pattern = If your pattern is "query sum of a range repeatedly" → use prefix sum array.
vector<int> getArrangementsDP(int k, int n){
    vector<int> dp(n + 1, 0);
    
    //number of arrangements when 0 flower = 1 ("")
    dp[0] = 1;
    //number of arrangements when 1 flower = dp[i] =  1 (R) --> THIS IS WRONG (as k >= 1, so for k == 1, 2 arrangements, {(R), (W)} = dp[1] = 2)
    //dp[i] = 1; (ALWAYS CHECK BASE CASES FROM NOW ON, ONCE CONVERTING MEMO TO ITERATIVE)
    
    for(int i = 1; i <= n; i++){
        dp[i] = (dp[i] % MOD + dp[i - 1] % MOD) % MOD;
        if(i - k >= 0){
            dp[i] = (dp[i] % MOD + dp[i - k] % MOD) % MOD;
        }
    }
    
    //prefix sum
    for(int i = 1; i <= n; i++){
        dp[i] = (dp[i] % MOD + dp[i - 1] % MOD) % MOD;
    }
    
    return dp;
}


int main() {
	// your code goes here
    int t, k;
    cin >> t >> k;
    int maxSequenceLength = 1;
    vector<pair<int, int> > cases(t);
    for(int i = 0; i < t; i++){
        cin >> cases[i].first >> cases[i].second;
        maxSequenceLength = max(maxSequenceLength, cases[i].second);
    }
    
    /*
    FIX THIS!, HOW CAN ANSWER QUERY WITH MEMO TABLE
    vector<int> memo(maxSequenceLength + 1, -1);
    //looped to just make sure every memo cell has been filled, most would already be filled as the first call was for max length
    for(int i = maxSequenceLength; i >= 0; i--){
        int res = getArrangements(0, k, i, memo);
    }
    
    
    //prefix sum
    for(int i = 1; i <= maxSequenceLength; i++){
        memo[i] += memo[i - 1];
    }
    
    */
    
    //Iterative DP call
    vector<int> dp = getArrangementsDP(k, maxSequenceLength);
    for(int i = 0; i < t; i++){
        int a = cases[i].first, b = cases[i].second;
        if(a > 0){
            int ans = dp[b] - dp[a  - 1];
            
            //KEEP IN MIND WHEN SUBTRACTING MODULO'ED VALUES
            if(ans < 0){
                ans += MOD;
            }
            cout << ans << '\n';
        }
        else{
            cout << dp[b] << '\n';
        }
    }
}
