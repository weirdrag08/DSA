class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> frq;
        unordered_set<string> used;
        string curr = "";
        int spaces = 0;
        for(int i = 0, j = 0; i <= s.size(); i++){
            if(i != s.size() && s[i] != ' '){
                curr += s[i];
            }
            else{
                spaces += 1;
                if(frq.count(pattern[j]) > 0){
                    if(frq[pattern[j]] != curr){
                        return false;
                    }
                }
                else{
                    if(used.find(curr) != used.end()){
                        return false;
                    }
                    frq[pattern[j]] = curr;
                    used.insert(curr);
                }
                j++;
                curr = "";
            }
        }
        return spaces == pattern.size() ? true : false;
    }
};
