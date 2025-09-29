/*
Easiest explanation: ❤️
🔹 Step 4: Algorithm

Iterate over nums:

For current number x = nums[i]:

Use binary search in tails to find the first element >= x (lower_bound).

If found, replace it (we found a smaller tail for that length).

If not found, append x to tails (we extended LIS by 1).

At the end, length of tails = LIS length.

🔹 Step 5: Example

nums = [10, 9, 2, 5, 3, 7, 101, 18]

Start with empty tails = []

10 → not found, append → [10]

9 → replace 10 → [9]

2 → replace 9 → [2]

5 → greater than 2, append → [2, 5]

3 → replace 5 → [2, 3]

7 → append → [2, 3, 7]

101 → append → [2, 3, 7, 101]

18 → replace 101 → [2, 3, 7, 18]

Result: LIS length = 4.
*/
class Solution {
public: 
    int bs(int num, vector<int> &tails){
        //Return the index of the number >= current number 'num', IF ANY
        int l = 0, r = tails.size() -  1, idx = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(tails[mid] < num){
                l = mid + 1;
            }
            else{
                idx = mid;
                r = mid - 1;
            }
        }
        return idx;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        //For every nums[i], SEARCH in tails, a number JUST greater than nums[i].
        //If such number exist, replace that number with nums[i]
        //Else, If (NO NUMBER) >= nums[i], append nums[i] in tails
        for(int i = 0; i < nums.size(); i++){
            int idx = bs(nums[i], tails);
            //found a number >= nums[i] (number JUST GREATER than nums[i])
            if(idx != -1){
                tails[idx] = nums[i];
            }
            else{
                tails.push_back(nums[i]);
            }
        }
        return tails.size();
    }
};
