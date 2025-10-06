#include <bits/stdc++.h>
using namespace std;

/*
As the question states that the elements are ATMOST k places to the left or right of their ACTUAL SORTED ORDER, so it means, If we sort in GROUPS OF (K + 1) elements, the whole array will be sorted eventually.

In normal unsorted arrays, an element can be ATMOST off by (N - 1) positions in the worst case, so that's why we need to consider the whole array AT ONCE, i.e a GROUP OF N ELEMENTS must be chosen at once, so that we can sort that element to it's correct position.

But this question states that an element can be ATMOST k places off it's correct position, so we just need to check a group of (K + 1), to sort that element to it's correct position.
*/

vector<int> sortKSortedArray(int k, vector<int> &v){
    priority_queue<int, vector<int>, greater<int> > pq;
    int pos = 0;
    for(int i = 0; i < v.size(); i++){
        //Add the first (k + 1) elements to min heap to form a valid group size that are in sorted order
        if(i <= k){
            pq.push(v[i]);
        }
        else{
            //print the min element out of (k + 1) elements, pop it, and add another element to maintain the (k + 1) group size
            v[pos] = pq.top();
            pos++;
            pq.pop();
            pq.push(v[i]);
        }
    }
    while(!pq.empty()){
        v[pos] = pq.top();
        pos++;
        pq.pop();
    }
    return v;
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
    sortKSortedArray(k, v);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}
