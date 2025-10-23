class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zeroCount = 0, res = 0;
        for(int i = 0, j = 0; i < nums.size(); i++){
            //Add element
            //Moving 'i' pointer increases the segment size and also the chances to add 0 in the segment
            if(nums[i] == 0){
                zeroCount += 1;
            }
            
            //If invalid, make it valid
            //Moving 'j' pointer decreases the segment size and also the chances to remove any added 0
            while(zeroCount > 0){
                if(nums[j] == 0){
                    zeroCount -= 1;
                }
                j++;
            }

            //BOTH the pointers are monotonic in nature, and are oppositely monotonic

            //Segment always valid, (only 1 in current segment)
            res = max(res, i - j + 1);
        }
        return res;
    }
};
