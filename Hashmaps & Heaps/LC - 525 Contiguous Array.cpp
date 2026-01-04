class Solution {
public:
    /*
    It CANNOT BE SOLVED with Sliding Window.
    Sliding Window requires monotonous behaviours for both pointers
    1 pointer should ALWAYS INCREASE a property, other should ALWAYS DECREASE that property or vice versa, essentially opposite behaviour for both (property such as SUM(only positive numbers), FREQUENCY(for a single element only), UNIQUE ITEM COUNTS are monotonous).
    That's why with negative elements you can't use SLIDING WINDOW for sum, as SUM can be increased or decreased depending on the element and the MONOTONIC behaviour is destroyed.

    In this question, we are tracking frequency but for 2 elements and not for single element. Extending the window, might make the frequencies of 0 or 1 equal, but it can decrease or increase the difference.
    Suppose there [0, 0, 1, 0, 1, 0]...extending this further might increase #0s (INCREASING THE DIFFERENCE) or increase the #1s (REDUCING THE DIFFERENCE), so the property is NOT MONOTONIC. 
    
    /*
    CONCLUSION -
    This problem CANNOT be solved using Sliding Window because the tracked property
    (the difference between counts of 0s and 1s) is non-monotonic with window expansion
    or contraction.
    
    GENERAL HEURISTIC:
    If Sliding Window fails due to lack of monotonicity, consider Prefix Sum + Hashing
    to detect repeated states (invariants) over ranges.
*/
    */
    int findMaxLength(vector<int>& nums) {
        //{sum, index}
        unordered_map<int, int> frq;
        int sum = 0, res = 0;
        frq[sum] = -1;
        for(int i = 0; i < nums.size(); i++){
            //Include element
            sum += nums[i] == 0 ? -1 : nums[i];
            
            //prefix[prevIdx] = X appears again at a later index prefix[currIdx] = X, i.e SUM[0, prevIdx] = SUM[0, currIdx], means sum in range[prevIdx, Idx] 
            if(frq.count(sum) > 0){
                res = max(res, i - frq[sum]);
            }
            else{
                frq[sum] = i;
            }
        }
        return res;
    }
};
