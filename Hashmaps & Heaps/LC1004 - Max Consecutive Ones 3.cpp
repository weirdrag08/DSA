class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, tolerance = 0;
        for(int i = 0, j = 0; i < nums.size(); i++){
            //add to tolerance when nums[i] = 0
            if(nums[i] == 0){
                tolerance += 1;
            }
            while(tolerance > k){
                if(nums[j] == 0){
                    tolerance -= 1;
                }
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
