class Solution {
public:
    const int INF = 1e9;
    bool isPalindrome(int i, int j, string &s, vector<vector<bool> > &memo){
        if(i >= j){
            if(i == j){
                return memo[i][j] = true;
            }
            return true;
        }
        if(memo[i][j]){
            return memo[i][j];
        }
        bool palindrome = false;
        if(s[i] == s[j]){
            palindrome = isPalindrome(i + 1, j - 1, s, memo);
        }
        
        return memo[i][j] = palindrome;
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

        //Precomputation O(N^2)
        vector<vector<bool> > palindromes(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i <= j){
                    bool palindrome = isPalindrome(i, j, s, palindromes);
                }
            }
        }
        vector<int> memo(n, -1);
        return minimumCuts(0, s, palindromes, memo);
    }
};
