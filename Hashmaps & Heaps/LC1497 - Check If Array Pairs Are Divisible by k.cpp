#include <bits/stdc++.h>
using namespace std;

bool IfPairsDivisibleByK(int k, vector<int> &nums){
    unordered_map<int, int> frq;
    for(int i = 0; i < nums.size(); i++){
        /*
            CAREFUL WHILE TAKING MODULO FOR NEGATIVE NUMBERS:
            rem = num % mod; WHEN num >= 0
            rem = (num % mod) + mod; WHEN num < 0
        */
        int rem = nums[i] % k;
        if(rem < 0){
            rem += k;
        }
        frq[rem] += 1;
    }
    bool res = true;
    for(auto p : frq){
        int rem1 = p.first;
        //If current rem exist, then only check
        if(frq[rem1] > 0){
            int rem2 = k - rem1;
            //Numbers divisible by k, can only pair with other numbers divisible by k, which means both the numbers have rem = 0.
            //So freq[rem = 0] should be EVEN
            if(rem1 == 0){
                res = frq[rem1] % 2 != 0 ? false : res;
            }
            else{
                res = frq[rem1] != frq[rem2] ? false : res;
            }
            if(!res){
                break;
            }
        }
    }
    return res;
}

int main() {
	// your code goes here
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> k;
    cout << IfPairsDivisibleByK(k, nums) << '\n';
}
