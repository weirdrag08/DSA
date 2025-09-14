#include <bits/stdc++.h>
using namespace std;

int minPart(int i, int j, string &s, vector<vector<bool> > &isPalindrome, vector<vector<int> > &memo){
    //string is empty, 0 character is already partitioned as palindrome, no cuts
    if(i > j){
        return 0;
    }
    
    //memo check
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    
    int minCost = INT_MAX;
    for(int k = i; k <= j; k++){
        //split at k only if the left half is a palindrome, and call recursively on right
        if(isPalindrome[i][k]){
            // if the whole substring s[i, j] is a palindrome, then minCuts required to make it a palindrome is 0;
            //Also could have been managed in base case, If the string passed is a palindrome, return 0
            int kSubstringCost = (k == j) ? 0 : 1;
            int rightCost = minPart(k + 1, j, s, isPalindrome, memo);
            minCost = min(minCost, kSubstringCost + rightCost);
        }
    }
    return memo[i][j] = minCost;
}

int minCut(string s){
    vector<vector<bool> > isPalindrome(s.size(), vector<bool>(s.size(), true));
    // i == j means a single character, a single character is always a palindrome
    for(int i = 0; i < s.size(); i++){
        for(int j = i + 1; j < s.size(); j++){
            for(int k = i, l = j; k < l; k++, l--){
                if(s[k] != s[l]){
                    isPalindrome[i][j] = false;
                    break;
                }
            }
        }
    }
    vector<vector<int> > memo(s.size(), vector<int>(s.size(), -1));
    return minPart(0, s.size() - 1, s, isPalindrome, memo);
}

int main() {
	// your code goes here
    string s;
    cin >> s;
    cout << minCut(s) << '\n';
}
