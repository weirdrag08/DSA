#include <bits/stdc++.h>
using namespace std;

int largestSubarray0Sum(vector<int> &v){
    //frq[sum] = index; i.e. that sum at which index
    //NOTE that we will keep the FIRST index at which a certain sum appeared
    //Because we want to find the longest subarray, we want the OLDEST/FIRST index a particular sum appeared
    unordered_map<int, int> frq;
    int sum = 0, res = 0;
    
    //Initially when no element was there, sum = 0
    //If including all the elements upto i, sum = 0, then the largest subarray with sum = 0, will be from (-1, i], which is (i - (-1));
    frq[sum] = -1;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
        
        //sum formed for the FIRST time, create entry
        if(frq.count(sum) == 0){
            frq[sum] = i;
        }
        //A sum reappeared, calculate size, don't update
        //size of subarray = (i - j) + 1, but this gives element in range [j, i] where i & j are inclusive
        //here the subarray sum = 0, includes element in range (j, i] where j exclusive & i inclusive, so size = (i - j)
        else{
            res = max(res, i - frq[sum]);
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
    cout << largestSubarray0Sum(v) << '\n';
}
