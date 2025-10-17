class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> frq;
        int res = 0;
        for(int i = 0, j = 0; i < s.size(); i++){
            //add element to segment
            frq[s[i]] += 1;

            //Character repeated, shorten segment to make it valid
            while(frq[s[i]] > 1){
                frq[s[j]] -= 1;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
