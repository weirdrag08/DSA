class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> frq;
        for(string s : strs){
            vector<int>  frqS(26, 0);
            for(char c : s){
                frqS[c - 'a'] += 1;
            }
            frq[frqS].emplace_back(s);
        }

        vector<vector<string> > res;
        for(auto p : frq){
            res.emplace_back(p.second);
        }
        return res;
    }
};
