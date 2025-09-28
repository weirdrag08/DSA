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
    //only jump to valid levels. (ALWAYS INCLUDE, as EXCLUSION DOES NOT BUILD SEQUENCE)
    if(memo[idx][firstIdx][second][size] != -1){
        return memo[idx][firstIdx][second][size];
    }
    int count = 0;
    bool loopRan = false;
	// ONE term is initialised in the sequence (prevIdx)
	//Extend for 2nd term (NO CONDITIONAL on 2nd term of sequence)
    if(!second){
        for(int i = idx + 1; i < nums.size(); i++){
            loopRan = true;
            count += getAllAPsOptimised(i, firstIdx, 1, size + 1, nums, memo);
        }
    }
    
    //TWO terms are initialized in the sequence (prevIdx, idx... )
    //Extend from 3rd TERM ONWARDS.
    else{
        for(int i = idx + 1; i < nums.size(); i++){
            if(1LL * nums[idx] - nums[firstIdx] == 1LL * nums[i] - nums[idx]){
                loopRan = true;
                count += getAllAPsOptimised(i, idx, second, size == 3 ? size : size + 1, nums, memo);
            }
        }
        //If loop ran, than the current number extended the sequence forwards. (ACTED AS AN INTERMEDIATE NODE IN SEQUENCE)
		//BUT IT COULD HAVE ALSO ACTED AS AN ENDPOINT for a VALID SEQUENCE IF SIZE OF SEQUENCE WHILE REACHING CURRENT NUMBER 
		//(including the current number) >= 3
		//Imagine the current path/sequence that is being built to be S(n) = 2, 4, 6(current number) .... 
		//Now for [idx+ 1, nums.size()), imagine there are 3 different 8's. So our current number (6), will extend the sequence in 3 different paths.
		// While recursion backtracks itself, memo[S(n)] = 3 (as there were 3 different paths, the sequence was extended, they would all return 1)
		// But 6 acted as an intermediate node which extended the sequence to all the 3 8s forward. 
		//But IT SHOULD ALSO ACT AS AN ENDPOINT FOR A VALID SEQUENCE 2, 4, 6, so count += 1

		//Condition loopRan is necessary, as if not present it would have double counted a sequence for which loop didn't run,
		//i.e. for the base condition. If the loop didn't run, which means it is an endpoint, and it's validity is being checked
		//below in the base case.
		if(loopRan){
			count = size >= 3 ? count + 1 : count;	
		} 
    }
    
    // All valid levels processed in the path(NO FURTHER TO JUMP TO), SEQUENCE CAN'T BE EXTENDED FROM HERE.
	//SO CHECK IF SEQUENCE FORMED IS VALID OR NOT (size >= 3), valid sequence otherwise invalid
    if(!loopRan){
        return memo[idx][firstIdx][second][size] = size >= 3 ? 1 : 0;
    }
	// IF any of the loop ran, it means that there was ATLEAST 1 valid level to jump from current Idx.
	// SEQUENCE WAS EXTENDED FROM HERE (not a endpoint, but an intermediate node in sequence), so don't check for VALIDITY
	// as it is not a base case.(THERE ARE STILL ELEMENTS LEFT THAT CAN BE PROCESSED IN THE PATH)
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
