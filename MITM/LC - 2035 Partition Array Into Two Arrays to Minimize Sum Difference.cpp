class Solution {
public:

    void genSubsetSum(int l, int r, int sum, int count, vector<int> &nums, unordered_map<int, vector<int> > &res){
        if(l > r){
            res[count].push_back(sum);
            return;
        }

        //inc in set
        genSubsetSum(l + 1, r, sum + nums[l], count + 1, nums, res);
        
        //exc from set
        genSubsetSum(l + 1, r, sum, count, nums, res);
    }

    int bs(int val, vector<int> &nums){
        int l = 0, r = nums.size() - 1, idx = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] > val){
                r = mid - 1;
            }
            else{
                idx = mid;
                l = mid + 1;
            }
        }
        return idx;
    }

    int minimumDifference(vector<int>& nums) {
        //CAREFUL: n here represents 2*N elements
        int n = nums.size(), totalSum = 0;
        for(int i : nums){
            totalSum += i;
        }
        //Divide nums in two half (Always even sized array)
        int l1 = 0, r1 = (n / 2) - 1, l2 = n / 2, r2 = n - 1;
        
       //Generate subset sum
       //{size, [sums]}
        unordered_map<int, vector<int> > left, right;
        genSubsetSum(l1, r1, 0, 0, nums, left);
        genSubsetSum(l2, r2, 0, 0, nums, right);


        //Sort a half
        //REMEMBER to access loops using '&' to SORT key-value pair BY REFERENCE to actually SORT the values in the map, instead of sorting the COPIES.
        for(auto &p : right){
            sort(p.second.begin(), p.second.end());
        }
        
        //x + y represent TOGETHER represent a singular partition, the remaning value from each half halves is responsible for the other partition
        //For each value (x) of unsorted half, BS on sorted half to find a value (y) which is the CLOSEST VALUE to (totalSum - x)
        //i.e. => y ≈ (totalSum - x), which is y >= totalSum - x or y <= totalSum - x (Neighbouring values)
        //S1 = x + y
        //S2 = totalSum - S1 => totalSum - (x + y)
        //OBJECTIVE: Min|S2 - S1| => Min|totalSum - (x + y) - (x + y)|
        //IMPORTANT => Min|totalSum - 2(x + y)|
        //It can be rewritten as:
        //totalSum - 2(x + y) ≈ 0
        //y ≈ (totalSum - 2x) / 2 (Also gives right answer)

        //Better Representation of the same equation would be:
        //x + y ≈ (totalSum / 2)
        // y ≈ (totalSum / 2) - x (BS condition to find value of y such that it is closest to totalSum - x)

        int ans = INT_MAX;
        for(auto p : left){
            int size = p.first;
            if(right.count((n / 2) - size) > 0){
                for(int i : p.second){
                    int x = i, y = -1;
                    int idx = bs((totalSum / 2) - x, right[(n / 2) - size]);
                    //Left neighbour
                    if(idx != -1){
                        y = right[(n / 2) - size][idx];
                        ans = min(ans, abs(totalSum - 2 * (x + y)));
                    }
                    //Right Neighbour
                    //The other closest value would be to the right of totalSum - x, i.e. > totalSum - x, which will be at idx + 1, if it exists
                    if(idx + 1 < right[(n / 2) - size].size()){
                        y = right[(n / 2) - size][idx + 1];
                        ans = min(ans, abs(totalSum - 2 * (x + y)));
                    }
                }
            }
        }
        return ans;
    }
};
