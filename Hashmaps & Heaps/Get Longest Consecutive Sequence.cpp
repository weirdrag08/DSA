#include <bits/stdc++.h>
using namespace std;

vector<int> getLongestConsecutiveSeq(vector<int> &v){
    unordered_map<int, int> frq;
    for(int i = 0; i < v.size(); i++){
        frq[v[i]] += 1;
    }
    vector<int> res;
    for(int i = 0; i < v.size(); i++){
        vector<int> path;
        for(auto it = frq.find(v[i]); it != frq.end();){
            path.push_back(it-> first);
            it = frq.find((it-> first) + 1);
        }
        if(path.size() > res.size()){
            res = path;
        }
    }
    return res;
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        
    }
    vector<int> res = getLongestConsecutiveSeq(v);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}
