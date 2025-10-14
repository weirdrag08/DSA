class Solution {
  public:
  
    int count0Subarray(vector<int> &arr){
        //map{sum, count}
        unordered_map<int, int> frq;
        
        //Before starting we have sum = 0.
        //To not miss a valid case where the sum till current i = 0
        int res = 0, sum = 0;
        frq[sum] = 1;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            //check if sum was repeated
            if(frq.count(sum) > 0){
                res += frq[sum];   
            }
            //add current sum to map
            frq[sum] += 1;
        }
        return res;
    }
  
    int findSubarray(vector<int> &arr) {
        // code here.
        return count0Subarray(arr);
    }
};
