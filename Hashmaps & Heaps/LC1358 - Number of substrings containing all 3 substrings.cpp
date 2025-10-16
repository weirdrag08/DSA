class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int, int> frq;
        int res = 0;
        for(int i = 0, j = 0; i < s.size(); i++){
            //add element
            if(s[i] == 'a' || s[i] == 'b' || s[i] == 'c'){
                frq[s[i]] += 1;
            }
            
            //while map size = 3 (i.e. all 3 characters present in segment), move left and make it invalid
            while(frq.size() == 3){
                frq[s[j]] -= 1;
                if(frq[s[j]] == 0){
                    frq.erase(s[j]);
                }
                j++;
            }
            //all the segment that starts to the left of 'j', excluding j, i.e. [0, j) are valid
            res += j;
        }
        return res;
    }
};
