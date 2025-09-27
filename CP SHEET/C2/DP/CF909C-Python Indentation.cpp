#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
// IMPORTANT - (Try and TRUST YOUR RECURSION AND MEMOISATION CAPABILITIES, and try to become BETTER IN TEST CASES GENERATION)
//a simple statement will not just decrease to just level - 1, but it can be anything
//level = 0 to level - 1
//as for this example = f f f s s, there are 4 ways
/*
f{
    f{
        f{
            s; 
            s; (last statement at same level as before)
        }
    }
}

OR

f{
    f{
        f{
            s;
        }
        s; (last statement at level - 1 as compared to previous statement)
    }
}

OR

f{
    f{
        f{
            s;
        }
    }
    s; (last statement at level - 2, as compared to previous statement)
}

OR

f{
    f{
        f{
            s;
        }
    }
}
s; (last statement at level - 3, as compared to to previous statement)

If the current statment is 's', then any next statement could be at: {level, level - 1, level - 2} NOT JUST {level, level - 1}. 

*/
//T.C = O(N^3), N^2 unique states, O(N) loop in each state  
int getWaysToIndent(int level, int idx, vector<char> &statements, vector<vector<int>> &memo){
    
    //all statements processed
    if(idx >= statements.size() - 1){
        return 1;
    }
    if(memo[level][idx] != -1){
        return memo[level][idx];
    }
    //levels = a statement
    //options = whether indent or keep at same level
    int count = 0;
    // A simple statement cannot indent to a deeper level
    // Provide multiple options - (keep at same level, or level - 1, or level - 2.... 0th level)
    //The next statement could be at same level bounding the end of innermost for loop. But it could also bound the outer for loops as well, or it could be at the same level as the outermost for loop
    if(statements[idx] == 's'){
        for(int i = 0; i <= level; i++){
            count = (count % MOD + getWaysToIndent(i, idx + 1, statements, memo) % MOD) % MOD;
        }
    }
    //if statement[idx] == for loop, always indent to a deeper level
    else{
        count = (count % MOD + getWaysToIndent(level + 1, idx + 1, statements, memo) % MOD) % MOD;        
    }
    
    return memo[level][idx] = count;
}

//O(N^3) as number of states = N^2, worst case calculation in each state = O(N)
//O(N^2) as number of states = N^2, calculation per state O(1) (CUMULATIVE SUM MARKING is O(1))
//V.V.V.V.IMPORTANT:
/*
If your pattern is "add to whole range repeatedly" → use cumulative sum marking.

If your pattern is "query sum of a range repeatedly" → use prefix sum array.
*/
int getWaysToIndentDP(vector<char> &statements){
    int n = statements.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    
    //statement at 0th index will always be at level 0, so only 1 way
    dp[0][0] = 1;
    
    //i -> idx
    for(int i = 1; i < n; i++){
        //j -> level
        for(int j = 0; j < n - 1; j++){
            //If previous statement, i.e. s[i - 1] == 's', then current statement s[i], can go to level -> [0, 1, 2, .... levelOf(s[i -1])].
            if(statements[i - 1] == 's'){
                //'j' represents the level, so the level of s[i - 1] statement is 'j'. So current statement could range from level {0, 1, 2,.... j}
                // for(int k = 0; k <= j; k++){
                //     //Statement[i - 1][j](statement (i - 1) at level 'j') can reach to statement (i) that is present level from [0, j] (same as memo function)
                //     dp[i][k] = (dp[i][k] % MOD + dp[i - 1][j] % MOD) % MOD;
                // }
                //Range Marked, take cumulative sum afterwards
                dp[i][0] = (dp[i][0] % MOD + dp[i - 1][j] % MOD) % MOD;
                dp[i][j + 1] = (dp[i][j + 1] % MOD - dp[i - 1][j] % MOD) % MOD;
                if(dp[i][j + 1] < 0){
                    dp[i][j + 1] += MOD;
                }
            }
            else{
               //If s[i - 1] == 'f' at level 'j', it could only reach the current statement s[i] at 
               //levels -> {levelOf(s[i - 1]) + 1}, as for causes the indentation 
               //Here s[i - 1] = f, is at level 'j', so it could only fill/reach the s[i] at level (j + 1)
               //Range Marked (CUMULATIVE SUM)
                dp[i][j + 1] = (dp[i][j + 1] % MOD + dp[i - 1][j] % MOD) % MOD;
                if(j < n - 2){
                    dp[i][j + 2] = (dp[i][j + 2] % MOD - dp[i - 1][j] % MOD) % MOD;
                    if(dp[i][j + 2] < 0){
                        dp[i][j + 2] += MOD;
                    }
                }
            }
        }
        //Cumulative Sum
        for(int j = 1; j < n; j++){
            dp[i][j] = (dp[i][j] % MOD + dp[i][j - 1] % MOD) % MOD;            
        }
    }
    
    
    //So the total number of ways to indent all 'n' statements would be sum of last column, representing n statements across all levels. SUM{dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], ...dp[n - 1][n - 1]}, as in worst case maxLevel = n - 1 (as level starts from 0). Eg - all simple statements
    int sum = 0;
    for(int j = 0; j < n; j++){
        sum = (sum % MOD + dp[n - 1][j] % MOD) % MOD;
    }
    return sum;
}


int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<char> statements(n);
    for(int i = 0; i < n; i++){
        cin >> statements[i];
    }
    // vector<vector<int> >  memo(n, vector<int>(n, -1));
    cout << getWaysToIndentDP(statements) << '\n';
}
