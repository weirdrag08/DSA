class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 0;
        for(int i = 0, j = 0; i < prices.size(); i++){
            if(i != 0 && prices[i - 1] - prices[i] != 1){
                j = i;
            }
            //count subarrays ending at i, starting from j in range [j, j + 1, ....j = i]
            count += i - j + 1;
        }
        return count;
    }
};
