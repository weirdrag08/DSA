class Solution {
public:
    int getMaxSumDP(int k, vector<int> &arr){
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for(int idx = n - 1; idx >= 0; idx--){
            int maxSum = 0, maxElement = 0;
            for(int j = idx; j < min((int) arr.size(), idx + k); j++){
                maxElement = max(maxElement, arr[j]);
                maxSum = max(maxSum, (j - idx + 1) * maxElement + dp[j + 1]);
            }
            dp[idx] = maxSum;
        }
        return dp[0];
    }
    int getMaxSum(int idx, int k, vector<int> &arr, vector<int> &memo){
        if(idx >= arr.size()){
            return 0;
        }

        if(memo[idx] != -1){
            return memo[idx];
        }

        //level = each idx
        //options = prefix starting from idx till size of subArray <= k
        int maxSum = 0, maxElement = 0;
        for(int i = idx; i < min((int) arr.size(), idx + k); i++){
            maxElement = max(maxElement, arr[i]);
            maxSum = max(maxSum, (i - idx + 1) * maxElement + getMaxSum(i + 1, k, arr, memo));
        }
        return memo[idx] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // vector<int> memo(arr.size(), -1);
        // return getMaxSum(0, k, arr, memo);
        return getMaxSumDP(k, arr);
    }
};
