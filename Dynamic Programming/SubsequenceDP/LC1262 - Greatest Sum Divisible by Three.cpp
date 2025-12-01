class Solution {
public:

    int getMaxSumDPOptimised(vector<int> &nums){
        int n = nums.size();
        vector<int> curr(3), next(3);
        
        //base case
        next[0] = 0, next[1] = INT_MIN, next[2] = INT_MIN;

        for(int idx = n - 1; idx >= 0; idx--){
            for(int rem = 0; rem <= 2; rem++){
                int inc = 0, exc = 0;
                inc = nums[idx] + next[(rem + nums[idx]) % 3];
                exc = next[rem];
                curr[rem] = max(inc, exc);
            }
            swap(curr, next);
        }
        return next[0];
    }

    int getMaxSumDP(vector<int> &nums){
        int n = nums.size();
        vector<vector<int> > dp(n + 1, vector<int>(3, -1));

        //base case
        dp[n][0] = 0, dp[n][1] = INT_MIN, dp[n][2] = INT_MIN;

        for(int idx = n - 1; idx >= 0; idx--){
            for(int rem = 0; rem <= 2; rem++){
                int inc = 0, exc = 0;
                inc = nums[idx] + dp[idx + 1][(rem + nums[idx]) % 3];
                exc = dp[idx + 1][rem];
                dp[idx][rem] = max(inc, exc);
            }
        }
        return dp[0][0];
    }

    int getMaxSumDivBy3(int idx, int rem, vector<int> &nums, vector<vector<int> > &memo){
        if(idx >= nums.size()){
            //Valid answer only in path where rem = 0
            if(rem == 0){
                return 0;
            }
            return INT_MIN;
        }
        if(memo[idx][rem] != -1){
            return memo[idx][rem];
        }
        //level = each item
        //options = inc or exc
        int inc = 0, exc = 0;
        inc = nums[idx] + getMaxSumDivBy3(idx + 1, (rem + nums[idx]) % 3, nums, memo);
        exc = getMaxSumDivBy3(idx + 1, rem, nums, memo);

        return memo[idx][rem] = max(inc, exc);
    }

    int maxSumDivThree(vector<int>& nums) {
        // vector<vector<int> > memo(nums.size(), vector<int>(3, -1));
        // return getMaxSumDivBy3(0, 0, nums, memo);
        // return getMaxSumDP(nums);
        return getMaxSumDPOptimised(nums);
    }
};
