class Solution {
  public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        if(s1.size() != s2.size()){
            return false;
        }
        vector<int> frq1(26, 0), frq2(26, 0); 
        // code here
        for(char s : s1){
            frq1[s - 'a'] += 1;
        }
        for(char s : s2){
            frq2[s - 'a'] += 1;
        }
        

        for(int i = 0; i < 26; i++){
            if(frq1[i] > frq2[i]){
              k -= frq1[i] - frq2[i];
            }
        }
        return k >= 0 ? true : false;
    }
};
