class Solution {
public:

    int isPalindrome(int i, int j, string &s, vector<vector<int> > &memo){
    if(i >= j){
        if(i == j){
            return memo[i][j] = 1;
        }
        return 1;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    char palindrome = 0;
    if(s[i] == s[j]){
        palindrome = isPalindrome(i + 1, j - 1, s, memo);
    }
    
    return memo[i][j] = palindrome;
}

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int> > memo(n, vector<int>(n, -1));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i <= j){
                    int palindrome = isPalindrome(i, j, s, memo);
                    if(palindrome == 1){
                        count += 1;
                    }
                }
            }
        }
        return count;
    }
};
