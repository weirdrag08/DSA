#include <bits/stdc++.h>
using namespace std;

int minCostToReachN(int stone, int n, vector<int> &height, vector<int> &memo){
    if(stone == n){
        return 0;
    }
    
    if(memo[stone] != -1){
        return memo[stone];
    }
    
    //level = stone
    //options = {stone + 1, stone + 2}
    
    int cost = INT_MAX;
    
    for(int i = 1; i <= 2; i++){
        if(stone + i <= n){
            cost = min(cost, abs(height[stone + i] - height[stone]) + minCostToReachN(stone + i, n, height, memo));
        }
    }
    return memo[stone] = cost;
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> height(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> height[i];
    }
    vector<int> memo(n + 1, -1);
    cout << minCostToReachN(1, n, height, memo) << '\n';
}
