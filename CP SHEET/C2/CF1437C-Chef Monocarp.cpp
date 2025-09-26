#include <bits/stdc++.h>
using namespace std;

int getUnpleasantValue(int currTime, int currIdx, vector<int> &dish, vector<vector<int> > &memo){
    // cout << currTime << " " << currIdx << '\n';
    // Time allotment limit exceeded
    if(currIdx < dish.size() && currTime > 2 * dish.size()){
        return INT_MAX;
    }
    //base case
    if(currIdx >= dish.size()){
        return 0;
    }
    
    //memo check
    if(memo[currTime][currIdx] != -1){
        return memo[currTime][currIdx];
    }
    
    // levels = currTime
    //options = INC = Take out / EXC = Not Take out, the currentIdx dish at level = currTime
    int inc = 0, exc = 0;
    //take out at time currTime, add the cost of taking out
    inc = getUnpleasantValue(currTime + 1, currIdx + 1, dish, memo);
    if(inc != INT_MAX){
        inc += abs(currTime - dish[currIdx]);
    }
    //not take out at time currTime
    exc = getUnpleasantValue(currTime + 1, currIdx, dish, memo);
    
    return memo[currTime][currIdx] = min(inc, exc);
}

int main() {
	// your code goes here
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> dish(n);
        for(int i = 0; i < n; i++){
            cin >> dish[i];
        }
        sort(dish.begin(), dish.end());
        vector<vector<int> > memo(2 * n + 1, vector<int>(n, -1));
        cout << getUnpleasantValue(1, 0, dish, memo) << '\n';
    }
}
