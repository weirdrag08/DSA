class Solution {
public:

    void genSubsetSum(int l, int r, int sum, vector<int> &nums, vector<int> &res){
        if(l > r){
            res.push_back(sum);
            return;
        }
        //level = each element
        //options = inc or exc
        genSubsetSum(l + 1, r, sum + nums[l], nums, res);
        genSubsetSum(l + 1, r, sum, nums, res);
    }

    int bs(int val, vector<int> &arr){
        int l = 0, r = arr.size() - 1, idx = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid] > val){
                r = mid - 1;
            }
            else{
                idx = mid;
                l = mid + 1;
            }
        }
        return idx;
    }

    int bsLarger(int val, vector<int> &arr){
        int l = 0, r = arr.size() - 1, idx = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid] >= val){
                idx = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return idx;
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        //Divide in 2 halfs
        int l1 = 0, r1 = 0, l2 = 0, r2 = nums.size() - 1;
        if(nums.size() % 2 == 0){
            r1 = (nums.size() / 2) - 1;
        }
        else{
            r1 = nums.size() / 2;
        }
        l2 = r1 + 1;

        // Generate All possible subset sum for each half
        vector<int> left, right;
        genSubsetSum(l1, r1, 0, nums, left);
        genSubsetSum(l2, r2, 0, nums, right);
        
        //Binary Search with condition for(x : left), find y such it is as close as possible to goal - x
        sort(right.begin(), right.end());

        int ans = INT_MAX;
        for(int i = 0; i < left.size(); i++){
            int x = left[i], y = -1;
            int idx = bs(goal - x, right);
            //IMPORTANT - The 2 closest value to goal - x will be the values to either side of goal - x
            // idx provides the value <= (goal - x), closest left value & the closest value to the right would be
            //(idx + 1), a value just greater than (goal - x).
            if(idx != -1){
                y = right[idx];
                ans = min(ans, abs(x + y - goal));
            }
            //if idx = -1, then the closest value of y to goal - x will be at idx = 0
            if(idx + 1 < right.size()){
                    y = right[idx  + 1];
                    ans = min(ans, abs(x  + y - goal));
            }
            if(ans == 0){
                return ans;
            }
        }
        return ans; 
    }
};
