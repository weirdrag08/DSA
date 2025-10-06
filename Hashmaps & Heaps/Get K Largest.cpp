#include <bits/stdc++.h>
using namespace std;

void getKLargest(int k, vector<int> &v){
    priority_queue<int> pq;
    for(int i = 0; i < v.size(); i++){
        pq.push(v[i]);
    }
    while(k--){
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
	// your code goes here
    int n, k;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> k;
    getKLargest(k, v);
}
