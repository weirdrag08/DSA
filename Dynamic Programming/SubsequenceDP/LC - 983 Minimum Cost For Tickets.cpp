class Solution {
public:

    int getNextIdx(int passEnd, vector<int> &days){
        int l = 0, r = days.size() - 1, idx = days.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(days[mid] > passEnd){
                idx = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return idx;
    }

    int getMinCostDP(vector<int> &days, vector<int> &costs){
        int n = days.size();
        //dp table
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            int minCost = 1e9;
            for(int j = 0; j < 3; j++){
                int pass = j == 0 ? 1 : j == 1 ? 7 : 30;
                int nextIdx = getNextIdx(days[i] + pass - 1, days);
                minCost = min(minCost, costs[j] + dp[nextIdx]);
            }
            dp[i] = minCost;
        }
        return dp[0];
    }

    int getMinCost(int idx, vector<int> &days, vector<int> &costs, vector<int> &memo){
        if(idx >= days.size()){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }
        //level = each day
        //options = 1,7,30
        int minCost = 1e9;
        for(int i = 0; i < 3; i++){
            int pass = i == 0 ? 1 : i == 1 ? 7 : 30;
            int nextIdx = getNextIdx(days[idx] + pass - 1, days);
            minCost = min(minCost, costs[i] + getMinCost(nextIdx, days, costs, memo));
        } 
        return memo[idx] = minCost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // sort(days.begin(), days.end());
        // vector<int> memo(days.size(), -1);
        // return getMinCost(0, days, costs, memo);
        return getMinCostDP(days, costs);
    }
};
