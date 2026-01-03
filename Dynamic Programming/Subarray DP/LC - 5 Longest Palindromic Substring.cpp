class Solution {
public:

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
