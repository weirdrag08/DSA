class Solution {
public:
    int getNextIdx(int end, vector<vector<int> > &events){
        int l = 0, r = events.size() - 1, idx = events.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(events[mid][0] > end){
                idx = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return idx;
    }
    int getMax(int idx, int k, vector<vector<int> > &events, vector<vector<int> > &memo){
        if(idx >= events.size()){
            return 0;
        }
        if(memo[idx][k] != -1){
            return memo[idx][k];
        }
        //levels = event
        //options = attend or not
        int inc = 0, exc = 0;
        if(k > 0){
            int nextIdx = getNextIdx(events[idx][1], events);
            inc = events[idx][2] + getMax(nextIdx, k - 1, events, memo);
        }
        exc = getMax(idx + 1, k, events, memo);
        return memo[idx][k] = max(inc, exc);
    }

    int getMaxDP(vector<vector<int> > &events){
        int n = events.size();
        vector<vector<int> > dp(n + 1, vector<int>(3, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int k = 0; k < 3; k++){
                int inc = 0, exc = 0;
                if(k > 0){
                    int nextIdx = getNextIdx(events[i][1], events);
                    inc = events[i][2] + dp[nextIdx][k - 1];
                }
                exc = dp[i + 1][k];
                dp[i][k] = max(inc, exc);
            }
        }
        return dp[0][2];
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        // vector<vector<int> > memo(events.size(), vector<int>(3, -1));
        // return getMax(0, 2, events, memo);
        return getMaxDP(events);
    }
};
