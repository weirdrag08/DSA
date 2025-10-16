class Solution {
public:
    int countSubarraysWithKOdd(int k, vector<int> &nums){
        int res = 0, countOdd = 0;
        for(int i = 0, j = 0; i < nums.size(); i++){
            //count odd
            if(nums[i] % 2 != 0){
                countOdd += 1;
            }
            //while invalid (countOdd > k), shorten segment
            while(countOdd > k){
                if(nums[j] % 2 != 0){
                    countOdd -= 1;
                }
                j++;
            }
            // All the segments whose left pointer is in range [l, r] -> {l + 1, l + 2 ...r} are valid 
            res += i - j + 1;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // #subarrays with exact k odd = #subarrays with atmost k - #subarrays with atmost (k - 1) odd
        // The difference = exactly k odd subarrays
        return countSubarraysWithKOdd(k, nums) - countSubarraysWithKOdd(k - 1, nums);
    }
};
