class Solution {
public:
    //whatever passenger has a pickup >= dropOff
    int getNextIdx(int dropOff, vector<vector<int> > &rides){
        int l = 0, r = rides.size() - 1, idx = rides.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(rides[mid][0] >= dropOff){
                idx = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return idx;
    }

    long long getMaxEarningsDP(vector<vector<int> > &rides){
        int n = rides.size();
        vector<long long> dp(rides.size() + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            long long inc = 0, exc = 0;
            int nextIdx = getNextIdx(rides[i][1], rides);
            inc = 1LL * (rides[i][1] - rides[i][0] + rides[i][2]) + dp[nextIdx];
            exc = 1LL * dp[i + 1];
            dp[i] = max(inc, exc);
        }
        return dp[0];
    }

    long long getMaxEarnings(int idx, vector<vector<int> > &rides, vector<long long> &memo){
        if(idx >= rides.size()){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }
        //level = each ride
        //options = give ride or not
        long long inc = 0, exc = 0;
        int nextIdx = getNextIdx(rides[idx][1], rides);
        inc = 1LL* (rides[idx][1] - rides[idx][0] + rides[idx][2]) + getMaxEarnings(nextIdx, rides, memo);
        exc = 1LL * getMaxEarnings(idx + 1, rides, memo);
        return memo[idx] = max(inc, exc);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        // vector<long long> memo(rides.size(), -1);
        // return getMaxEarnings(0, rides, memo);
        return getMaxEarningsDP(rides);
    }
};
