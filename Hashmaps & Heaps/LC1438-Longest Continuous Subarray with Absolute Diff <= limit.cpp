class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> frq;
        int res = 0;
        for(int i = 0, j = 0; i < nums.size(); i++){
            //add element
            frq[nums[i]] += 1;

            //If by adding the above element, segment becomes invalid, make it valid by shortening the segment
            while(prev(frq.end())-> first - frq.begin()-> first > limit){
                frq[nums[j]]--;
                if(frq[nums[j]] == 0){
                    frq.erase(nums[j]);
                }
                j++;
            }
            //Segment always valid here
            res = max(res, i - j + 1);
        }
        return res;
    }
};
