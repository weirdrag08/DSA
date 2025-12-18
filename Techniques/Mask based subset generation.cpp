#include <bits/stdc++.h>
using namespace std;

void getAllSubsetsRecursion(int idx, int sum, vector<int> &nums, vector<int> &res){
    if(idx >= nums.size()){
        res.push_back(sum);
        return;
    }
    getAllSubsetsRecursion(idx + 1, sum + nums[idx], nums, res);
    getAllSubsetsRecursion(idx + 1, sum, nums, res);
}


//N size array, total possible subsets = 2^N
//All the subsets can be represented by integer in range[0, 2^N - 1]
//N = 3, total possible subsets = 2^3 = 8
//They can be represented by integer in range[0, 7]
//000
//001
//010
//011
//100
//101
//110
//111
vector<int> getAllSubsets(vector<int> &v){
    int n = v.size();
    vector<int> res;
    //Each mask(integer) value represents a subset configuration in their binary form
    for(int i = 0; i < (1 << n); i++){
        int sum = 0;
        //For each subset configuration, check what bit was on, and add that sum
        for(int j = 0; j < n; j++){
            //jth bit ON
            if(i & (1 << j)){
                sum += v[j];                
            }
        }
        res.push_back(sum);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    //Generate subsets via mask
    vector<int> subsets = getAllSubsets(v);
    cout << "Iterative subset generation via mask: \n";
    for(int i : subsets){
        cout << i << " ";
    }

    //Generate subsets via recursion
    vector<int> res;
    getAllSubsetsRecursion(0, 0, v, res);
    sort(res.begin(), res.end());
    cout << "\nRecursive Subset generation: \n";
    for(int i : res){
        cout << i << " ";
    }
}
