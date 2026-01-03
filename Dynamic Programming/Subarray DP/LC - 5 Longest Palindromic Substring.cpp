class Solution {
public: 
    
    vector<vector<bool> > isPalindromeDP(string &s){
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        
        //base case
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i >= j){
                    dp[i][j] = true;
                }
            }
        }
        
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(i < j){
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }
        return dp;
    }

    bool isPalindrome(int i, int j, string &s, vector<vector<bool> > &palindrome){
        if(i >= j){
            if(i == j){
                return palindrome[i][j] = true;
            }
            return true;
        }
        if(palindrome[i][j]){
            return palindrome[i][j];
        }
        bool pal = false;
        if(s[i] == s[j]){
            pal = isPalindrome(i + 1, j - 1, s, palindrome);
        }
        return palindrome[i][j] = pal;
    }

    string longestPalindrome(string s) {
        vector<vector<bool> > palindrome(s.size(), vector<bool>(s.size(), false));
        int l = 0, r = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                palindrome[i][j] = isPalindrome(i, j, s, palindrome);
                if(palindrome[i][j] && r - l + 1 < j - i + 1){
                    l = i;
                    r = j;
                }
            }
        }
        return s.substr(l, r - l + 1);
    }
};
