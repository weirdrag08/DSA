#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int getCoinPermutations(int x, vector<int> &coins, vector<int> &memo){
    if(x == 0){
        return 1;
    }
    
    if(memo[x] != -1){
        return memo[x];
    }
    
    //level = x
    //options = each coin denomination
    int res = 0;    
    for(int i = 0; i < coins.size(); i++){
        if(x >= coins[i]){
            res = (res % MOD + getCoinPermutations(x - coins[i], coins, memo) % MOD) % MOD;
        }
    }
    return memo[x] = res;
}

int main() {
	// your code goes here
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    vector<int> memo(x + 1, -1);
    cout << getCoinPermutations(x, coins, memo) << '\n';
    
}
