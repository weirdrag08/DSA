class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> frq;
        unordered_set<char> used;
        for(int i = 0; i < s.size(); i++){
            if(frq.count(s[i]) > 0){
                if(frq[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                if(used.find(t[i]) != used.end()){
                    return false;
                }
                frq[s[i]] = t[i];
                used.insert(t[i]);
            }
        }
        return true;
    }
};
