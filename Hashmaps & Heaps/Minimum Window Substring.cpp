#include <bits/stdc++.h>
using namespace std;

string minWindowSubstring(string &s, string &t){
    unordered_map<char, int> frqT;
    unordered_map<char, int> frqS;
    int diff = 0;
    int start = -1, size = 0;
    for(char c : t){
        frqT[c] += 1;
    }
    diff = frqT.size();
    
    for(int i = 0, j = 0; i < s.size(); i++){
        //Add the element to hashmap
        frqS[s[i]] += 1;
        
        //current char exists in string t
        if(frqT.count(s[i]) > 0 && frqS[s[i]] == frqT[s[i]]){
            diff--;
        }
        
        //Valid segment formed, calculate answer, minimise it, recalculate till the segment becomes invalid
        while(diff == 0){
            if(start == -1 || i - j + 1 < size){
                start = j;
                size = i - j + 1;
            }
            // Remove j, till the segment becomes invalid
            frqS[s[j]]--;
            if(frqT.count(s[j]) > 0 && frqS[s[j]] < frqT[s[j]]){
                diff++;
            }
            j++;
        }
    }
    string res = "";
    //A valid segment exists
    if(start != -1){
        res = s.substr(start, size);
    }
    return res;
}

int main() {
	// your code goes here
    string s, t;
    cin >> s >> t;
    cout << minWindowSubstring(s, t) << '\n';
}
