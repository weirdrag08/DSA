#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8;

int getArrangements(int n1, int n2, int footmenPlaced, int horsemenPlaced, int k1, int k2, vector<vector<vector<vector<int> >  > > &memo){
    //All footmen and horsemen placed
    if(n1 == 0 && n2 == 0){
        return 1;
    }
    
    //memo check
    if(memo[n1][n2][footmenPlaced][horsemenPlaced] != -1){
        return memo[n1][n2][footmenPlaced][horsemenPlaced];
    }
    //levels = position
    //options = place footmen or horsemen
    int count = 0;
    
    //Place footmen if property not violated, reset horsemen consecutively placed = 0
    if(n1 > 0 &&  footmenPlaced < k1){
        count = (count % MOD + getArrangements(n1 - 1, n2, footmenPlaced + 1, 0, k1, k2, memo) % MOD) % MOD;
    }
    // Place horsement if property not violated, reset footmen consecutively placed = 0;
    if(n2 > 0 && horsemenPlaced < k2){
        count = (count % MOD + getArrangements(n1, n2 - 1, 0, horsemenPlaced + 1, k1, k2, memo) % MOD) % MOD;
    }
    return memo[n1][n2][footmenPlaced][horsemenPlaced] = count;
}

int main() {
	// your code goes here
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    vector<vector<vector<vector<int> > > > memo(n1 + 1, vector<vector<vector<int> > >(n2 + 1, vector<vector<int> >(k1 + 1, vector<int>(k2 + 1, -1))));
    cout << getArrangements(n1, n2, 0, 0, k1, k2, memo) << '\n';
}
