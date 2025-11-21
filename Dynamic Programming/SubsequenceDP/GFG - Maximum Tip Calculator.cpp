
class Solution {
  public:
    
    long long getMaxTipDp1D(int x, int y, vector<int> &arr, vector<int> &brr){
        int n = arr.size();
        //
        vector<long long> filled(x + 1, 0), toFill(x + 1, 0);
        
        for(int idx = n - 1; idx >= 0; idx--){
            for(int aCount = 0; aCount <= x; aCount++){
                long long orderA = 0, orderB = 0;
                if(aCount < x){
                    orderA = 1LL * arr[idx] + filled[aCount + 1];
                }
                if(idx - aCount < y){
                    orderB =  1LL * brr[idx] + filled[aCount];
                }
                toFill[aCount] = max(orderA, orderB);
            }
            swap(toFill, filled);
        }
        
        return filled[0];
    }
  
  
    long long getMaxTipDp2D(int x, int y, vector<int> &arr, vector<int> &brr){
        int n = arr.size();
        
        //base case
        vector<vector<long long> > dp(n + 1, vector<long long>(x + 1, 0));
        
        for(int idx = n - 1; idx >= 0; idx--){
            for(int aCount = 0; aCount <= x; aCount++){
                long long orderA = 0, orderB = 0;
                if(aCount < x){
                    orderA = arr[idx] + dp[idx + 1][aCount + 1];
                }
                if(idx - aCount < y){
                    orderB = brr[idx] + dp[idx + 1][aCount];
                }
                dp[idx][aCount] = max(orderA, orderB);
            }
        }
        return dp[0][0];
    }
  
  
    long long getMaxTipMemo(int idx, int aCount, int x, int y, vector<int> &arr, vector<int> &brr, vector<vector<long long> > &memo){
        if(idx >= arr.size()){
            return 0;
        }
        
        if(memo[idx][aCount] != -1){
            return memo[idx][aCount];
        }
        
        //level = each order
        //option = taken by A or B if limit allows
        long long orderA = 0, orderB = 0;
        //A
        if(aCount < x){
            orderA = 1LL * arr[idx] + getMaxTipMemo(idx + 1, aCount + 1, x, y, arr, brr, memo);
        }
        
        //B
        if(idx - aCount < y){
            orderB = 1LL * brr[idx] + getMaxTipMemo(idx + 1, aCount, x, y, arr, brr, memo);
        }
        
        return memo[idx][aCount] = max(orderA, orderB);
    }
  
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        // vector<vector<long long> > memo(n, vector<long long>(x + 1, -1));
        // return getMaxTipMemo(0, 0, x, y, arr, brr, memo);
        return getMaxTipDp1D(x, y, arr, brr);
    }
};
