#include <bits/stdc++.h>
using namespace std;

class Number{
    public:
    int val, list, idx;
    
    Number(int val, int list, int idx){
        this-> val = val;
        this-> list = list;
        this-> idx = idx;
    }
};

class Compare{
    public:
    
    // b would be higher priority than a, when b.val < a.val 
    bool operator()(const Number &a, const Number &b){
        return b.val < a.val;
    }
};

vector<int> mergeKSortedLists(vector<vector<int> > &kLists){
    priority_queue<Number, vector<Number>, Compare> pq;
    
    //Insert the first element of every list
    for(int i = 0; i < kLists.size(); i++){
        if(kLists[i].size() > 0){
            pq.emplace(kLists[i][0], i, 0);
        }
    }
    vector<int> res;
    while(!pq.empty()){
        Number top = pq.top();
        pq.pop();
        
        int val = top.val, list = top.list, idx = top.idx;
        
        //Add element to res
        res.push_back(val);
        
        //Insert the next element from the list to which the top belongs to
        if(idx + 1 < kLists[list].size()){
            pq.emplace(kLists[list][idx + 1], list, idx + 1);
        }
    }
    return res;
}

int main() {
	// your code goes here
    int k, n, element;
    cin >> k;
    vector<vector<int> > kLists(k);
    
    for(int i = 0; i < k; i++){
        cin >> n;
        //init each of the k list
        kLists[i] = vector<int>(n);
        for(int j = 0; j < n; j++){
            cin >> kLists[i][j];
        }
    }
    vector<int> res = mergeKSortedLists(kLists);
    for(int i : res){
        cout << i << " ";
    }
}
