#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//Forms permutation by trying each valid option at each level
int getWaysToFormSumPermutation(int n, vector<int> &memo){
    if(n == 0){
        return 1;
    }
    
    if(memo[n] != -1){
        return memo[n];
    }
    
    //level = n
    //options = {1, 2, 3, 4, 5, 6} 
    int res = 0;
    for(int face = 1; face <= 6; face++){
        if(n >= face){
            res = (res % MOD + getWaysToFormSumPermutation(n - face, memo) % MOD) % MOD;
        }
    }
    return memo[n] = res;
}

//Avoids permutation by keeping order, and allows repetition by including the face in subset but keeping the same face (NON DECREASING ORDER OF FACES, as (face or face + 1) are the only options)
int getWaysToFormSumCombWithRep(int face, int n){
    
    if(n == 0){
        return 1;
    }
    
    /*
    OPTION 1: {face, n - face} //inc (inclusion with repetition)
    OPTION 2: {face + 1, n} //exc    (exclusion)
    
    */
    
    int inc = 0, exc = 0;
    
    // face part of subset, but repetition allowed
    if(n >= face){
        inc = getWaysToFormSumCombWithRep(face, n - face);
    }
    //face not part of subset, so move to next face
    if(face < 6){
        exc = getWaysToFormSumCombWithRep(face + 1, n);
    }
    
    return (inc % MOD + exc % MOD) % MOD;
}

//Generates combination, but avoids repetition by including the face in subset and moving to next
int getWaysToFormSumCombWithoutRep(int face, int n){
    if(n == 0){
        return 1;
    }
    //level = n
    //options = include current face or exclude it
    
    /*
    OPTION 1: {face + 1, n - face} //inc WITHOUT repetition
    OPTION 2: {face + 1, n} // exclusion
    
    */
    
    int inc = 0, exc = 0;
    
    if(n >= face && face < 6){
        inc = getWaysToFormSumCombWithoutRep(face + 1, n - face);
    }
    if(face < 6){
        exc = getWaysToFormSumCombWithoutRep(face + 1, n);
    }
    return (inc % MOD + exc % MOD) % MOD;
}



int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> memo(n + 1, -1);
    cout << getWaysToFormSumPermutation(n, memo) << '\n';
    // cout << getWaysToFormSumCombWithRep(1, n) << '\n';
    // cout << getWaysToFormSumCombWithoutRep(1, n) << '\n';
}
