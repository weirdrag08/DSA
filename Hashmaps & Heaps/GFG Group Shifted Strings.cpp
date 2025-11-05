
class Solution {
  public:
  
    string calculateKey(string &s){
        string key = "";
        for(int i = 1; i < s.size(); i++){
            int diff = s[i] - s[i - 1];
            if(diff < 0){
                diff += 26;
            }
            key += to_string(diff);
        }
        return key;
    }
  
    vector<vector<string>> groupShiftedString(vector<string> &arr) {
        // Your code here
        unordered_map<string, vector<string> > frq;
        for(int i = 0; i < arr.size(); i++){
            string s = arr[i];
            //for each string calculate relative difference between consecutive characters
            //As relative difference between characters in shifted strings remain the same
            string key = calculateKey(s);
            frq[key].emplace_back(s);
        }
        vector<vector<string> > res;
        for(auto p : frq){
            res.push_back(p.second);
        }
        return res;
    }
};
