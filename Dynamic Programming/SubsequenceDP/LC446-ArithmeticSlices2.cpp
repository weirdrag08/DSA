#include <bits/stdc++.h>
using namespace std;

int getAllAPs(int idx, int nMinus2, int nMinus1, int size, vector<int> &nums){
    if(idx >= nums.size()){
        if(size >= 3){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int count = 0;
    if(nMinus2 == -1){
        //inc of FIRST term (no conditional required, any number can be the FIRST in sequence)
        count += getAllAPs(idx + 1, idx, nMinus1, size + 1, nums);
    }
    else{
        if(nMinus1 == -1){
            //inc of SECOND term (no condition required, any number can be the SECOND in sequence)
            count += getAllAPs(idx + 1, nMinus2, idx, size + 1, nums);
        }
        else{
            //inc of 3rd and ONWARDS(only include, if it does not violate the property of AP)
            if(1LL * nums[nMinus1] - nums[nMinus2] == 1LL * nums[idx] - nums[nMinus1]){
                count += getAllAPs(idx + 1, nMinus1, idx, size + 1, nums);
            }
        }
    }
    //exc never violates the sequence, as it does not extend the sequence, keeps it the same
    //As exc doesn't change anything(nMinus2, nMinus1, size), there is only 1 way to call
    count += getAllAPs(idx + 1, nMinus2, nMinus1, size, nums);
    return count;
}


int getAllAPsOptimised(int idx, int firstIdx, int second, int size, vector<int> &nums, vector<vector<vector<vector<int> > > > &memo){

    // cout << nums[firstIdx] << " " << nums[idx] << " " << size << '\n';
    //only jump to valid levels. (ALWAYS INCLUDE, as EXCLUSION DOES NOT BUILD SEQUENCE)
    if(memo[idx][firstIdx][second][size] != -1){
        return memo[idx][firstIdx][second][size];
    }
    int count = 0;
    bool loopRan = false;
    if(!second){
        for(int i = idx + 1; i < nums.size(); i++){
            loopRan = true;
            count += getAllAPsOptimised(i, firstIdx, 1, size + 1, nums, memo);
        }
    }
    
    //First two terms are initialized (firstIdx, idx... )
    //Extend via loop
    else{
        for(int i = idx + 1; i < nums.size(); i++){
            if(1LL * nums[idx] - nums[firstIdx] == 1LL * nums[i] - nums[idx]){
                loopRan = true;
                count += getAllAPsOptimised(i, idx, second, size == 3 ? size : size + 1, nums, memo);
            }
        }
        //(A valid sequence found = (someprevious, firstIdx, idx))
        count = size >= 3 ? count + 1 : count; 
    }
    
    // All valid levels processed(NO FURTHER TO JUMP TO), check size >= 3, valid sequence otherwise invalid
    if(!loopRan){
        return memo[idx][firstIdx][second][size] = size >= 3 ? 1 : 0;
    }
    else{
        return memo[idx][firstIdx][second][size] = count;
    }
}


int getCount(vector<int> &nums){
//   return getAllAPs(0, -1, -1, 0, nums);
    int count = 0, n = nums.size();
    vector<vector<vector<vector<int> > > > memo(n, vector<vector<vector<int> > >(n, vector<vector<int> >(2, vector<int>(4, -1))));
    //Give every element the chance to be the first in the SEQUENCE.
    for(int i = 0; i < nums.size(); i++){
        count += getAllAPsOptimised(i, i, 0, 1, nums, memo);
    }
    return count;
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << getCount(nums) << '\n';
}
