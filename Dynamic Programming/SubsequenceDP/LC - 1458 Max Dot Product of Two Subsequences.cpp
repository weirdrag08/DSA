class Solution {
public:
    const int nINF = -1e9;

    int maxProductOptimised(vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size(), m = nums2.size();
        //Currently next is at i = n, and curr is row that we are filling via loops, which is currently at i = n - 1
        vector<vector<int> > curr(m + 1, vector<int>(2, 0)), next(m + 1, vector<int>(2, 0));
        
        //All subproblems where j == m && empty = false, return 0
        for(int j = 0; j <= m; j++){
            next[j][1] = nINF;
        }
        //curr will always be in range, where i = {i - 1, i - 2.....0}
        //but j is range {m, m - 1, ....0}
        // k is in range {0, 1}
        // so the 1-e9 would be where = forALL(i)[m][1] states storing answer for where nums1.substr(i), nums2.size() = 0, empty = 1 
        curr[m][1] = nINF;

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                for(int k = 0; k <= 1; k++){
                    int c1m = nINF, mc2 = nINF, c1mc2 = nINF;
                    c1m = curr[j + 1][k];
                    mc2 = next[j][k];
                    c1mc2 = nums1[i] * nums2[j] + next[j + 1][0];
                    curr[j][k] = max(c1mc2, max(c1m, mc2));
                }
            }
            swap(curr, next);
        }
        return next[0][1];
    }

    int maxProductDP(vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size(), m = nums2.size();
        //dp table
        vector<vector<vector<int> > > dp(n + 1, vector<vector<int> > (m + 1, vector<int>(2, 0)));

        //base case
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                //If empty = true, not a valid set (non - empty subsequences) 
                if(i == n || j == m){
                    dp[i][j][1] = nINF;
                }
            }
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                for(int empty = 0; empty <= 1; empty++){
                    int c1m = nINF, mc2 = nINF, c1mc2 = nINF;
                    c1m = dp[i][j + 1][empty];
                    mc2 = dp[i + 1][j][empty];
                    c1mc2 = nums1[i] * nums2[j] + dp[i + 1][j + 1][0];
                    dp[i][j][empty] = max(c1mc2, max(c1m, mc2));
                }
            }
        }
        return dp[0][0][1];
    }

    int maxProduct(int i, int j, bool empty, vector<int> &nums1, vector<int> &nums2, vector<vector<vector<int> > > &memo){
        if(i >= nums1.size() || j >= nums2.size()){
            if(!empty){
                return 0;
            }
            return nINF;
        }
        if(memo[i][j][empty] != -1){
            return memo[i][j][empty];
        }
        //level each i & j
        //option = either take dot product or not
        int c1m = nINF, mc2 = nINF, c1mc2 = nINF;
        c1m = maxProduct(i, j + 1, empty, nums1, nums2, memo);
        mc2 = maxProduct(i + 1, j, empty, nums1, nums2, memo);
        c1mc2 = nums1[i] * nums2[j] + maxProduct(i + 1, j + 1, false, nums1, nums2, memo); 
        return memo[i][j][empty] = max(c1mc2, max(c1m, mc2));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<vector<int> > > memo(nums1.size(), vector<vector<int>>(nums2.size(), vector<int>(2, -1)));
        // return maxProduct(0, 0, true, nums1, nums2, memo);
        // return maxProductDP(nums1, nums2);
        return maxProductOptimised(nums1, nums2);
    }
};
