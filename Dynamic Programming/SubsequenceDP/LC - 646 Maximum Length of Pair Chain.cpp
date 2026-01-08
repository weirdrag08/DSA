class Solution {
public:
    int getNextIdx(int b, vector<vector<int> > &pairs){
        int l = 0, r = pairs.size() - 1, idx = pairs.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(pairs[mid][0] > b){
                idx = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return idx;
    }
    
    int getLongestChainDP(vector<vector<int> > &pairs){
        int n = pairs.size();
        //dp table
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            int inc = 0, exc = 0;
            int nextIdx = getNextIdx(pairs[i][1], pairs);
            inc = 1 + dp[nextIdx];
            exc = dp[i + 1];
            dp[i] = max(inc, exc);
        }
        return dp[0];
    }

    int getLongestChain(int idx, vector<vector<int> > &pairs, vector<int> &memo){
        //All pairs considered in current path
        if(idx >= pairs.size()){
            return 0;
        }
        //memo check
        if(memo[idx] != -1){
            return memo[idx];
        }
        //level = pair at idx
        //options = jump to a pair at some 'nextIdx' where pairs[nextIdx][0] > pairs[idx][1], i.e just greater

        int inc = 0, exc = 0;
        
        //If the current index pair,i.e. pairs[idx] is included in the set, what's the FIRST VALID 'nextIdx' that is available
        //
        int nextIdx = getNextIdx(pairs[idx][1], pairs); 
        inc = 1 + getLongestChain(nextIdx, pairs, memo);

        //If the current index pair is excluded, the next valid index = idx + 1
        exc = getLongestChain(idx + 1, pairs, memo);
        return memo[idx] = max(inc, exc);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        // vector<int> memo(pairs.size(), -1);
        // return getLongestChain(0, pairs, memo);
        return getLongestChainDP(pairs);
    }
};
