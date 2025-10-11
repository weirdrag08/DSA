#include <bits/stdc++.h>
using namespace std;


vector<int> countDistinctInWindowK(int k, vector<int> &arr){
    unordered_map<int, int> frq;
    vector<int> res;
    for(int i = 0, j = 0; i < arr.size(); i++){
        frq[arr[i]] += 1;
        //window of size k is formed
        if(i >= k - 1){
            res.push_back(frq.size()); 
            j = i - (k - 1);
            frq[arr[j]] -= 1;
            if(frq[arr[j]] == 0){
                frq.erase(arr[j]);
            }
            j++;
        }
    }
    return res;
}


int main() {
	// your code goes here
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    vector<int> res = countDistinctInWindowK(k, arr);
    for(int i : res){
        cout << i << " ";
    }
}
/*
16
3 3 4 3 2 3 4 3 3 2 1 2 3
4
*/ 
