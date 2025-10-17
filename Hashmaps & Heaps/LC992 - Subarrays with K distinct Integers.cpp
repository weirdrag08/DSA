class Solution {
public:
     // 2 pointers work because
     // moving 'i', increases segment, increases #distinct integers
     // moving 'j' decreases segment, decrease #distinct integers
    //Returns #subarray with atmost k different integers
    int countSubarrayWithKDifferent(int k, vector<int> &nums){
        unordered_map<int, int> frq;
        int res = 0;
        for(int i = 0, j = 0; i < nums.size(); i++){
            //Add element to segment
            frq[nums[i]] += 1;
            
            //If invalid, i.e. #different integers in segment > k, make it valid, move left pointer
            while(frq.size() > k){
                frq[nums[j]] -= 1;
                if(frq[nums[j]] == 0){
                    frq.erase(nums[j]);
                }
                j++;
            }
            // #good subarrays for a given 'i', are all the segments where 'j' in range[j, r]
            //All those segments have #distinct integers <= k
            res += i - j + 1;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarrayWithKDifferent(k, nums) - countSubarrayWithKDifferent(k - 1, nums);
    }
};
