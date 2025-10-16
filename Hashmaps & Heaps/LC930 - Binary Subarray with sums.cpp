class Solution {
public:
    //Function to #subarray with atmost goal 1s, i.e. #1s <= goal
    int countSubarrayWithAtmostGoal(int goal, vector<int> &nums){
        int res = 0, count = 0;
        for(int i = 0, j = 0; i < nums.size(); i++){
            //Track count of 1s
            if(nums[i] == 1){
                count += 1;
            }
            //Shorten segment till #1s in the current segment > goal
            while(count > goal){
                if(nums[j] == 1){
                    count -= 1;
                }
                j++;
            }
            //For current 'r', count all the valid segments.
            //All the valid segments, all 'l' between [l, r] are valid segment starters
            res += i - j + 1;
        }
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //#subarray with 1s count <= goal - #subarray with 1s count <= (goal - 1)
        //The difference = #Subarray with 1s count == goal
        return goal == 0 ? countSubarrayWithAtmostGoal(goal, nums) : countSubarrayWithAtmostGoal(goal, nums) - countSubarrayWithAtmostGoal(goal - 1, nums);
    }
};
