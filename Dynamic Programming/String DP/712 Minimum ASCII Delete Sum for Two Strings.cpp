class Solution {
public:
    const int INF = 1e9;

    int getMinDPOptimised(string &s1, string &s2){
        int n = s1.size(), m = s2.size();

        //curr and next
        vector<int> curr(m + 1, 0), next(m + 1, 0);

        //storing Suffix Sum of s2 in next, as next is currently at i = n
        int sum = 0;
        for(int j = m - 1; j >= 0; j--){
            sum += s2[j];
            next[j] = sum;
        }
        int suffixS1 = 0;
        for(int i = n - 1; i >= 0; i--){
            next[m] = suffixS1;
            suffixS1 += s1[i];
            curr[m] = suffixS1;
            for(int j = m - 1; j >= 0; j--){
                int path1 = INF, path2 = INF, path3 = INF;
                if(s1[i] == s2[j]){
                    path1 = next[j + 1];
                }
                else{
                    path2 = s1[i] + next[j];
                    path3 = s2[j] + curr[j + 1];
                }
                curr[j] = min(path1, min(path2, path3));
            }
            swap(curr, next);
        }
        return next[0];
    }

    int getMinDP(string &s1, string &s2){
        int n = s1.size(), m = s2.size();
        //dp table
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

        vector<int> suffixS1(n, 0), suffixS2(m, 0);
        int sum = 0;
        //suffix sum of s1
        for(int i = n - 1; i >= 0; i--){
            sum += s1[i];
            dp[i][m] = sum;
        }
        sum = 0;
        for(int j = m - 1; j >= 0; j--){
            sum += s2[j];
            dp[n][j] = sum;
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int path1 = INF, path2 = INF, path3 = INF;
                if(s1[i] == s2[j]){
                    path1 = dp[i + 1][j + 1];
                }
                else{
                    //delete s[i]
                    path2 = s1[i] + dp[i + 1][j];
                    //delete s[j];
                    path3 = s2[j] + dp[i][j + 1];
                }
                dp[i][j] = min(path1, min(path2, path3));
            }
        }
        return dp[0][0];
    }

    int getMin(int i, int j, string &s1, string &s2, vector<vector<int> > &memo){
        if(i >= s1.size() || j >= s2.size()){
            int sum = 0;
            while(i < s1.size()){
                sum += s1[i];
                i++;
            }
            while(j < s2.size()){
                sum += s2[j];
                j++;
            }
            return sum;
        }
        
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        //level = s[i] && s[j]
        //options = whether to delete s[i], OR delete s[j], or not delete at all
        //if same don't delete it
        //If a character is same in both strings for some pos i in s1 and j in s2, then keep it.
        //As we need to minimise the sum of deleted character, which is to minimise deletion itself
        int path1 = INF, path2 = INF, path3 = INF;
        if(s1[i] == s2[j]){
            path1 = getMin(i + 1, j + 1, s1, s2, memo);
        }
        else{
            // delete s1[i], keep s2[j]
            path2 = s1[i] + getMin(i + 1, j, s1, s2, memo);
            //delete s2[j], keep s1[i]
            path3 = s2[j] + getMin(i, j + 1, s1, s2, memo);
        }
        return memo[i][j] = min(path1, min(path2, path3));
    }

    int minimumDeleteSum(string s1, string s2) {
        // vector<vector<int> > memo(s1.size(), vector<int>(s2.size(), -1));
        // return getMin(0, 0, s1, s2, memo);
        // return getMinDP(s1, s2);
        return getMinDPOptimised(s1, s2);
    }
};
