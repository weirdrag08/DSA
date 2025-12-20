class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 0;
        for(int i = 0, j = 0; i < prices.size(); i++){
            if(i == prices.size() - 1){
                count += i - j + 1;
            }
            else{
                //if current endpoint (i) satisfies the condition, count all subarray ending at 'i' starting for all j in range[j, i]
                if(prices[i] - prices[i + 1] == 1){
                    count += i - j + 1;
                }
                //If the next endpoint(i + 1) breaks condition, first count all subarrays ending at 'i' then move j to start the count afresh from next endpoint i + 1
                else{
                    count += i - j + 1;
                    j = i + 1;
                }
            }
        }
        return count;
    }
};
