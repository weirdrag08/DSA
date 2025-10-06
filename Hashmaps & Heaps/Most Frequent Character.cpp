#include <bits/stdc++.h>
using namespace std;

int getMostFrequent(vector<int> &v){
    unordered_map<int, int> frq;
    for(int i = 0; i < v.size(); i++){
        frq[v[i]] += 1;
    }
    int maxFreqChar = frq.begin()-> first;
    for(auto p : frq){
        if(p.second > frq[maxFreqChar]){
            maxFreqChar = p.first;
        }
    }
    return maxFreqChar;
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << getMostFrequent(v) << '\n';
}
