#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int getCount(int level, int sum, int &k, bool inc, int weight, vector<vector<int> > &memo){
    if(sum < 0){
        return 0;
    }
    //found a valid path
    if(sum == 0 && inc){
        return 1;
    }
    
    //memo check
    if(memo[sum][inc] != -1){
        return memo[sum][inc];
    }
    //level = node
    //options = k options
    int count = 0;
    for(int i = 1; i <= k; i++){
        count = (count % MOD + getCount(level + 1, sum - i, k, i >= weight ? 1 : inc, weight, memo) % MOD) % MOD;
    }
    return memo[sum][inc] = count;
}

int main() {
	// your code goes here
    int sum, k, weight;
    cin >> sum >> k >> weight;
    vector<vector<int> > memo(sum + 1, vector<int>(2, -1));
    cout << getCount(0, sum, k, 0, weight, memo) << '\n';
}
