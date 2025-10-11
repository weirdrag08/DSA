class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int zeroCount = 0;
        long long count = 0;
        for(int i = 0; i < nums.size(); i++){
            //add count to consecutive 0
            if(nums[i] == 0){
                zeroCount += 1;
            }
            //an element != 0 encounted, count subarrays, flush all  0s, start afresh
            else{
                count += (1LL * zeroCount * (zeroCount + 1)) / 2;
                zeroCount = 0;
            }
        }
        if(zeroCount > 0){
            count += (1LL * zeroCount * (zeroCount + 1)) / 2;
        }
        return count;
    }
};
