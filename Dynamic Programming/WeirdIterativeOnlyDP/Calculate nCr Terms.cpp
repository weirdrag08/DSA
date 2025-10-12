#include <bits/stdc++.h>
using namespace std;

vector<int> getTerms(int n){
    if(n == 0){
        vector<int> base = {1};
        return base;
    }
    vector<int> prevRow = {1, 1};
    if(n == 1){
        return prevRow;
    }
    for(int i = 2; i <= n; i++){
        vector<int> currentRow = {1};
        for(int j = 1; j < i; j++){
            currentRow.push_back(prevRow[j - 1] + prevRow[j]);
        }
        currentRow.push_back(1);
        prevRow = currentRow;
        // for(int i : prevRow){
        //     cout << i << " ";
        // }
        // cout << '\n';
    }
    return prevRow;
}

int main() {
	// your code goes here
    int n, r;
    cin >> n >> r;
    vector<int> terms = getTerms(n);
    int sum = 0;
    for(int i = 1; i <= r; i++){
        sum += terms[i];
    }
    cout << sum << '\n';
    
}
