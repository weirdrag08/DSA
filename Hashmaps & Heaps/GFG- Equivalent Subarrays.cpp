class Solution {
  public:
  
    int countAtmostDistinct(int arr[], int n, int distinct){
        unordered_map<int, int> frq;
        int res = 0;
        for(int i = 0, j = 0; i < n; i++){
            //Add element to increase the #distinct
            frq[arr[i]] += 1;
            
            //While #distinct > k, reduce #distinct
            while(frq.size() > distinct){
                frq[arr[j]] -= 1;
                if(frq[arr[j]] == 0){
                    frq.erase(arr[j]);
                }
                j++;
            }
            //Current segment [j....i], have #distinct <= distinct, valid segment
            //All the segments inside [j....i], where j in range [j, r] are valid
            res += i - j + 1;
        }
        return res;
    }
  
    int countDistinctSubarray(int arr[], int n) {
        // code here.
        unordered_map<int, int> distinctEle;
        for(int i = 0; i < n; i++){
            distinctEle[arr[i]] += 1;
        }
        int distinct = distinctEle.size();
        return countAtmostDistinct(arr, n, distinct) - countAtmostDistinct(arr, n, distinct - 1);
    }
};
