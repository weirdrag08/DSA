#include <bits/stdc++.h>
using namespace std;

/*
IMPORTANT THEORY- 
TO GENERATE EVERY SUBARRAYS FOR AN ARRAY via recursion, simply break into prefixes & suffixes, CALCULATE on the PREFIX and CALL on the SUFFIX

As we have generate subarrays, in recursion to generate subarrays is by generating prefixes and suffixes of range
For a range [l......k......r] => [l, k] is the prefix of [l, r], and [k + 1, r] is the suffix of [l, r]

To generate each subarray of [l, r], generate each prefix of [l, r], and recursively call on the remaining suffix for every prefix.

In simple terms, for a range [l, r]
Generate each prefix (by looping k from l + 1, r), and for each prefix[l, k], call on the suffix [k + 1, r].
The current prefix of [l, r] is your SUBARRAY/SUBSTRING in CONSIDERATION / CURRENT SUBSTRING OR CURRENT SUBARRAY.
So every CALCULATION will be done on PREFIXES, and every CALL will be done on the SUFFIXES.

*/

int getAPCount(int l, int r, vector<int> &nums, vector<vector<int> > &memo){
    // base case (it is not actually needed, because it is managed by the loop)
    if(r - l < 2){
        return 0;
    }
    
    //memo check
    if(memo[l][r] != -1){
        return memo[l][r];
    }
    //Generate each prefix for range [l, r] by looping k from [l, r]
     // prefix / current subarray [l, k]
     // OBSERVATION - Common Difference / CD will be defined by the first two terms of the sequence of every valid subarray.
     //so for a range [l, r], Every prefix of [l, r], the first two terms will l & l + 1, so C.D. = (l + 1)th - (l) 
     int count = 0;
     int cd = nums[l + 1] - nums[l];
    bool validPrefix = true;
    for(int k = l; k <= r; k++){
        //Once a prefix is INVALID, the other prefix formed at the current level are extension of it, so they will be invalid as well
        if(k > 0 && nums[k] - nums[k - 1] != cd){
            validPrefix = false;
        }
        //CALCULATE on the PREFIX
        if(k - l >= 2 && nums[k] - nums[k - 1] == cd && validPrefix){
            // if current subarray / current prefix is a VALID AP (size >= 3 and cd is consistent)
            count += 1;
        }
        //CALL on the SUFFIX[k + 1, r] to generate rest of the subarrays & get their count by recursion.
        count += getAPCount(k + 1, r, nums, memo);
    }
    return memo[l][r] = count;
}

int numberOfArithmeticSlices(vector<int> &nums){
    int n = nums.size();
    vector<vector<int> >  memo(n, vector<int>(n, - 1));
    return getAPCount(0, n - 1, nums, memo);
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << numberOfArithmeticSlices(nums) << '\n';
}
