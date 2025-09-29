#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubseq(int l, int r, string &s, vector<vector<int> > &memo){
    if(l > r){
        return 0;
    }
    //
    if(l == r){ 
        return 1;
    }
    
    //memo check
    if(memo[l][r] != -1){
        return memo[l][r];
    }
    
    int count = 0;
    if(s[l] == s[r]){ 
        int fm = countPalindromicSubseq(l + 1, r - 1, s, memo);
        // + 3 because (c1 itself is a palindrome, c2 itself is a palindrom & "c1c2" is also a valid palindrome in f(c1mc2), if c1 == c2)
        count = 2 * fm + 3;
    }
    else{ 
        int fc1m = countPalindromicSubseq(l, r - 1, s, memo);
        int fmc2 = countPalindromicSubseq(l + 1, r, s, memo);
        int fm = countPalindromicSubseq(l + 1, r - 1, s, memo);
        count = fm + (fc1m - fm) + (fmc2 - fm); 
        
    }
    return memo[l][r] = count;
}

int countPS(string s){ 
    int n = s.size();
    vector<vector<int> > memo(n, vector<int>(n, -1));
    return countPalindromicSubseq(0, s.size() - 1, s, memo); 
}
int main() {
	// your code goes here
    string s;
    cin >> s; 
    cout << countPS(s) << '\n';
}
