class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0, count = 0;
            for(int div = 1; div * div <= nums[i]; div++){
                //A divisor of nums[i] is div and then the other one is nums[i] / div
                if(nums[i] % div == 0){
                    sum += div;
                    count += 1;
                    //Not a perfect square of div, then nums[i] / div is different than div
                    if(nums[i] / div != div){
                        sum += nums[i] / div;
                        count += 1;
                    }
                }
            }

            //Have exactly 4 divisors, add the sum to result
            if(count == 4){
                res += sum;
            }
        }
        return res;
    }
};
