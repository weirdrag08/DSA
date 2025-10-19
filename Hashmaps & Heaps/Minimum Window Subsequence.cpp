#include <bits/stdc++.h>
using namespace std;

int subseqPresent(int l, int r, string &s1, string &s2){
    int k = 0;
    for(int i = l; i <= r && k < s2.size(); i++){
        if(s1[i] == s2[k]){
            k++;
        }
    }
    return k;
}

string minWindow(string &s1, string &s2){
    int start = -1, length = INT_MAX, k = 0;
    for(int i = 0, j = 0; i < s1.size(); i++){
        //Add element
        if(s1[i] == s2[k]){
            k++;
        }
        //While valid, calculate answer, Make it Invalid by moving 'j'
        while(k == s2.size()){
            //Calculate answer
            if(i - j + 1 < length){
                start = j;
                length = i - j + 1;
            }
            
            //Remove 'j', and check if the s2 is present as a subsequence in the current segment
            j++;
            k = subseqPresent(j, i, s1, s2);
        }
    }
    return start == -1 ? "" : s1.substr(start, length);
}

int main() {
	// your code goes here
    string s1, s2;
    cin >> s1 >> s2;
    cout << minWindow(s1, s2) << '\n';
}
