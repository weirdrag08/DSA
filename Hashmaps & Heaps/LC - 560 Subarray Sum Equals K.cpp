class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //{sum, count}
        unordered_map<int, int> frq;
        int sum = 0, count = 0;
        frq[sum] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(frq.count(sum - k) > 0){
                count += frq[sum - k];
            }
            frq[sum] += 1;
        }
        return count;
    }
};
