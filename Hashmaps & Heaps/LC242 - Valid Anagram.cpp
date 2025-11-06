class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> frqS(26, 0), frqT(26, 0);
        for(int i = 0; i < s.size(); i++){
            frqS[s[i] - 'a'] += 1;
        }

        for(int i = 0; i < t.size(); i++){
            frqT[t[i] - 'a'] += 1;
        }
        //Compare frequency maps of both string, if same then anagram otherwise not
        return frqS == frqT ? true : false;
    }
};
