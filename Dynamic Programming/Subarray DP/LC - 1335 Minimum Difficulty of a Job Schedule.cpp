class Solution {
public:

    //max Difficulty achievable is #jobs = 300, and each job[i] is 1000, and we do 1 job each day
    // there are at max 10 days, and any batch can have max difficulty of 1000
    // 1000 * 10 = 10000
    const int INF = 1e8;


    int getMinDifficultyDP(int d, vector<int> &jobs){
        int n = jobs.size();
        //dp table
        vector<vector<int> > dp(n + 1, vector<int>(d + 1, INF));

        //base case
        dp[n][0] = 0;

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= d; j++){
                int prefixDifficulty = 0, res = INF;
                for(int k = i; k < n; k++){
                    if(j > 0){
                        prefixDifficulty = max(prefixDifficulty, jobs[k]);
                        res = min(res, prefixDifficulty + dp[k + 1][j - 1]);
                    }
                    else{
                        break;
                    }
                }
                dp[i][j] = res;
            }
        }
        return dp[0][d];
    }


    int getMinDifficulty(int i, int d, vector<int> &jobs, vector<vector<int> > &memo){
        if(i >= jobs.size()){
            if(d == 0){
                return 0;
            }
            else{
                return INF;
            }
        }

        if(memo[i][d] != -1){
            return memo[i][d];
        }

        //levels = each i
        //options = prefix starting at i ...ending at some j
        int prefixDifficulty = 0, res = INF;
        //for each i, choose a valid j => {computation on prefix[i, j] + call on suffix[j + 1, n - 1]}
        for(int j = i; j < jobs.size(); j++){
            //days left
            if(d > 0){
                prefixDifficulty = max(prefixDifficulty, jobs[j]);
                res = min(res, prefixDifficulty + getMinDifficulty(j + 1, d - 1, jobs, memo));
            }
            else{
                break;
            }
        }
        return memo[i][d] = res;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        //Impossible only when #jobs < d, as it is mandatory schedule atleast 1 job each day
        if(n < d){
            return -1;
        }
        // vector<vector<int> > memo(n, vector<int>(d + 1, -1));
        // return getMinDifficulty(0, d, jobDifficulty, memo);
        return getMinDifficultyDP(d, jobDifficulty);
    }
};
