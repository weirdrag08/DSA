class Solution {
public:
    const int INF = 1e9;
    vector<vector<bool> > isPalindromeDP(string &s){
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));

        //base case
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Empty strings and 1 length string all palindromes
                if(i >= j){
                    dp[i][j] = true;
                }
            }
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                //valid substring s.substr(i, j - i + 1)
                if(i < j){
                    bool palindrome = false;
                    if(s[i] == s[j]){
                        palindrome = dp[i + 1][j - 1];
                    }
                    dp[i][j] = palindrome;
                }
            }
        }
        return dp;
    }
    
    int minimumCutsDP(string &s, vector<vector<bool> > &palindromes){
        int n = s.size();
        vector<int> dp(n + 1, -1);

        //base case
        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--){
            int count = INF;
            for(int j = i; j < n; j++){
                if(palindromes[i][j]){
                    count = min(count, (j + 1) == n ? 0 : 1 + dp[j + 1]);
                }
            }
            dp[i] = count;
        }
        return dp[0];
    }

    int minimumCuts(int idx, string &s, vector<vector<bool> > &palindromes, vector<int> &memo){
        if(idx >= s.size()){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }
        //level = each char at idx;
        //options = palindromic prefix starting at idx, call on suffix
        int count = INF;
        for(int i = idx; i < s.size(); i++){
            // Valid Prefix / Prefix is a palindrome, call on suffix to compute further
            if(palindromes[idx][i]){
                // cout << "root: " << s.substr(idx) << " child: " << s.substr(i + 1) << '\n';
                //If the prefix = the whole string, then there were no cuts made
                count = min(count, (i + 1) == s.size() ? 0 : 1 + minimumCuts(i + 1, s, palindromes, memo));
            }
        }
        return memo[idx] = count;
    }

    int minCut(string s) {
        int n = s.size();

        //Precomputation O(N^2) - Precompute all the palindromic substrings, to compute prefix validity in O(1)
        vector<vector<bool> > palindromes = isPalindromeDP(s);
        // vector<int> memo(n, -1);
        // return minimumCuts(0, s, palindromes, memo);
        return minimumCutsDP(s, palindromes);
    }
};
