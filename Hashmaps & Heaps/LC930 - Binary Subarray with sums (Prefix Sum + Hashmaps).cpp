class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> prefix(nums.size(), 0);
        //frq{p[x], count(p[x])}
        unordered_map<int, int> frq;
        int count = 0;

        prefix[0] = nums[0];
        //compute p[i] = prefix function for nums, i.e. sum[0...i]
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        //#prefix sum = 0, before starting traversal initial sum = 0
        frq[0] = 1;
        for(int i = 0; i < prefix.size(); i++){
            //p[r] - p[l - 1] = k => p[l - 1] = p[r] - k;
            //#valid subarrays = For a given p[r], #p[l - 1] with value = p[r] - k 
            if(frq.count(prefix[i] - goal) > 0){
                count += frq[prefix[i] - goal];               
                //insert current element
            }
            frq[prefix[i]] += 1;
        }
        return count;
    }
};
