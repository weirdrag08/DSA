class Solution {
public:

    int getLongestAP(int idx, int cd, int cdRange, vector<int> &nums, vector<vector<int> > &memo){
        if(memo[idx][cd + cdRange] != -1){
            return memo[idx][cd + cdRange];
        }
        //If idx is reached, it means it was a valid level(part of sequence, so it's length will get counted)
        int length = 0;
        bool loopRan = false;
        //only jump to levels that are valid relative to current level, i.e. a difference with c.d.
        for(int i = idx + 1; i < nums.size(); i++){
            if(nums[i] - nums[idx] == cd){
                loopRan = true;
                length = max(length, 1 + getLongestAP(i, cd, cdRange, nums, memo));
            }
        }
        //If loopRan, then the value of the current level got correctly added (+ 1), otherwise it didn't get added
        //Alternatively, If loop didn't run, which means there was no further valid level to jump to, i.e. the sequence can't be extended further and it's an endpoint for the current sequence getting built by the recursion.
        return memo[idx][cd + cdRange] = loopRan ? length : 1;
    }

    int longestArithSeqLength(vector<int>& nums) {
        //select 2 terms with given difference to get the first 2 terms of the sequence, {nums[i], nums[j]}
        //set c.d. = nums[j] - nums[i]
        int n = nums.size();
        int longestAPlength = 0, minValue = INT_MAX, maxValue = 0;
        for(int i = 0; i < n; i++){
            minValue = min(minValue, nums[i]);
            maxValue = max(maxValue, nums[i]);
        }
        int cdRange = maxValue - minValue;
        vector<vector<int> > memo(n, vector<int>(2 * cdRange + 1, -1));
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int cd = nums[j] - nums[i];
                //CAREFUL - Even though the nested loop builds the first 2 terms(nums[i], nums[j]) in the AP, you cannot call recursion from j + 1.
                //Because the JUMP DP version that I write assumes that ANY LEVEL REACHED IS VALID AND IT'S CONTRIBUTION SHOULD BE COUNTED.
                //That's why you can't start recursion from j + 1, because nums[j + 1] is not a VALID NUMBER(cd == nums[j] - nums[i]) that could be included in the sequence.
                // {i, j...} are the valid sequence, because the first 2 terms set the CD.
                //2nd term onwards, only the level with same CD should be reached. But if you just call on nums[j + 1], as j + 1 was reached in recursion, it's contribution will be counted, i.e. it will extend the sequence (even though the CD for it was not checked)
                // But we know nums[j] is valid and part of the current sequence with CD as = nums[j] - nums[i]
                //So call from nums[j], now jth index is reached in recursion, it's contribution will counted. So NO need to EXPLICITLY count it's contribution outside of recursion.
                // Only count the contribution of nums[i], outside of recursion
                //That's why 1 added here, counting the contribution of nums[i]. Contribution of nums[j] will counted inside recursion as it was reached during recursion, so it's a valid level/a part of the current AP sequence
                longestAPlength = max(longestAPlength, 1 + getLongestAP(j, cd, cdRange, nums, memo));
            }
        }
        return longestAPlength;
    }
};
