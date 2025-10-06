#include <bits/stdc++.h>
using namespace std;

vector<int> getCommonElements2(vector<int> &a1, vector<int> &a2){
    unordered_map<int, int> frq;
    //traverse a1 and store in map
    for(int i = 0; i < a1.size(); i++){
        frq[a1[i]] += 1;
    }
    
    vector<int> res;
    
    //traverse a2 
    for(int i = 0; i < a2.size(); i++){
        if(frq[a2[i]] > 0){
            res.push_back(a2[i]);
            frq[a2[i]]--;
        }
    }
    return res;
}

int main() {
	// your code goes here
    int n, m;
    cin >> n >> m;
    vector<int> a1(n), a2(m);
    for(int i = 0; i < n; i++){
        cin >> a1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> a2[i];
    }
    vector<int> res = getCommonElements2(a1, a2);
    for(int i : res){
        cout << i << " ";
    }
}
