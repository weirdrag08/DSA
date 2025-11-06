class Solution {
public:

    bool checkAnagram(vector<int> &frqS, vector<int> &frqP){
        return frqS == frqP ? true : false;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> frqP(26, 0), frqS(26, 0);
        int uniqueChar = 0;
        for(char c : p){
            if(frqP[c - 'a'] == 0){
                uniqueChar += 1;
            }
            frqP[c - 'a'] += 1; 
        }

        int diff = uniqueChar;
        vector<int> res;
        for(int i = 0, j = 0; i < s.size(); i++){
            frqS[s[i] - 'a'] += 1;

            if(frqS[s[i] - 'a'] == frqP[s[i] - 'a']){
                diff -= 1;
            }

            while(diff == 0){   
                //check if anagram
                if(checkAnagram(frqS, frqP)){
                    res.push_back(j);
                }

                frqS[s[j] - 'a'] -= 1;

                //if extra char to spare
                if(frqP[s[j] - 'a'] > frqS[s[j] - 'a']){
                    diff += 1;
                }
                j++;
            }
        }
        return res;
    }
};
