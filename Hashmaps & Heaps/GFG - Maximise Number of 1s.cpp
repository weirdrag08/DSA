class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int res = 0, zeroCount = 0;
        for(int i = 0, j = 0; i < arr.size(); i++){
            //If element = 0, increase #0 count
            if(arr[i] == 0){
                zeroCount += 1;
            }
            //If invalid , (zeroCount > k)
            while(zeroCount > k){
                if(arr[j] == 0){
                    zeroCount -= 1;
                }
                j++;
            }
            //Segment always valid here, (zeroCount <= k)
            res = max(res, i - j + 1);
        }
        return res;
    }
};
