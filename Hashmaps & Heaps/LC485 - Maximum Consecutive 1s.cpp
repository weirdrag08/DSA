class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cons1 = 0;
        for(int i = 0; i < nums.size(); i++){
            //if 1 found, increase count of consecutive 1 otherwise set it to 0
            cons1 = nums[i] == 1 ? cons1 + 1 : 0;
            res = max(res, cons1);
        }
        return res;
    }
};
