#include <bits/stdc++.h>
using namespace std;

int getMinCostToReachN(int stone, int N, int K, vector<int> &height, vector<int> &memo){
    //Min cost to reach N for stone N = 0
    if(stone == N){
        return 0;
    }
    
    if(memo[stone] != -1){
        return memo[stone];
    }
    
    //level = stone
    //options = {stone + 1, stone + 2, .....  min(N, stone + K)}
    int cost = INT_MAX;
    for(int i = 1; i <= K; i++){
        if(stone + i <= N){
            cost = min(cost, abs(height[stone + i] - height[stone]) + getMinCostToReachN(stone + i, N, K, height, memo));
        }
    }
    return memo[stone] = cost;
}

int main() {
	// your code goes here
    int n, K;
    cin >> n >> K;
    vector<int> height(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> height[i];
    }
    vector<int> memo(n + 1, -1);
    cout << getMinCostToReachN(1, n, K, height, memo) << '\n';
}
