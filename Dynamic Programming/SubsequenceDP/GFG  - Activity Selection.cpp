class Solution {
  public:
  
    int getNextIdx(int idx, vector<vector<int> > &activities){
        int l = 0, r = activities.size() - 1, nextIdx = activities.size();
        while(l <= r){
            int mid = (l + r) / 2;
            //start time of next> end time of current activity
            if(activities[mid][0] > activities[idx][1]){
                nextIdx = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return nextIdx;
    }
    
    int getMaxActivitiesDP(vector<vector<int> > &activities){
        int n = activities.size();
        //dp table
        vector<int> dp(n + 1, 0);
        
        for(int i = n - 1; i >= 0; i--){
            int inc = 0, exc = 0;
            int nextIdx = getNextIdx(i, activities);
            inc = 1 + dp[nextIdx];
            exc = dp[i + 1];
            dp[i] = max(inc, exc);
        }
        return dp[0];
    }
  
    int getMaxActivities(int idx, vector<vector<int> > &activities, vector<int> &memo){
        if(idx >= activities.size()){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }
        //level = activity at idx
        //options = do or don't
        int inc = 0, exc = 0;
        int nextIdx = getNextIdx(idx, activities);
        inc = 1 + getMaxActivities(nextIdx, activities, memo);
        exc = getMaxActivities(idx + 1, activities, memo);
        return memo[idx] = max(inc, exc);
    }
  
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<vector<int> > activities(start.size(), vector<int>(2, 0));
        for(int i = 0; i < start.size(); i++){
            activities[i][0] = start[i], activities[i][1] = finish[i];
        }
        sort(activities.begin(), activities.end());
        // vector<int> memo(activities.size(), -1);
        // return getMaxActivities(0, activities, memo);
        return getMaxActivitiesDP(activities);
    }
};
