#include <bits/stdc++.h>
using namespace std;

long long getMaxValue(int idx, int W, vector<int> &weight, vector<int> &value, vector<vector<long long> > &memo){
    if(idx >= weight.size()){
        return 0;
    }
    
    if(memo[idx][W] != -1){
        return memo[idx][W];
    }
    
    //level = idx/item
    //options = inc or exc
    
    long long inc = 0, exc = 0;
    
    //include only knapsack allows
    if(W >= weight[idx]){
        inc = 1LL * value[idx] + getMaxValue(idx + 1, W - weight[idx], weight, value, memo);
    }
    
    //exclude
    exc = getMaxValue(idx + 1, W, weight, value, memo);
    
    return memo[idx][W] = max(inc, exc);
}

int main() {
	// your code goes here
    int n, W;
    cin >> n >> W;
    vector<int> weight(n), value(n);
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
    }
    //memo{n, W} => {100, 1e5}
    vector<vector<long long> > memo(n, vector<long long>(W + 1, -1));
    cout << getMaxValue(0, W, weight, value, memo) << '\n';
}
