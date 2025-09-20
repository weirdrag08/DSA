#include <bits/stdc++.h>
using namespace std;

int findBeacon(int beacon, vector<pair<int, int> > &beacons){
    int l = 0, r = beacon - 1, idx = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(beacons[mid].first < beacons[beacon].first - beacons[beacon].second){
            idx = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return idx;
}

int getMaxActivated(int beacon, vector<pair<int, int> > &beacons, vector<int> &memo){
    //memo check
    if(memo[beacon] != -1){
        return memo[beacon];
    }
    // cout << pos[beacon] << " " << '\n';
    //level = the beacon
    //options = WE CHOOSE ONLY THAT OPTION THAT MAXMISES OUR ANSWER.
    //HERE WE HAVE 2 OPTIONS, WHETHER TO ACTIVATE THE BEACON OR NOT
    //ACTIVATION of beacon, guarantees that it will NOT BE DESTROYED(maximises the answer), MORE BEACONS ACTIVATED, MORE SURVIVE
    
    //ACTIVATE CURRENT BEACON
    //Find the NEXT VALID LEVEL to jump to (THE FIRST LEFT BEACON TO THE LEFT OF CURRENT BEACON THAT IS NOT INSIDE THE BLAST RANGE OF CURRENT BEACON)
    
    //current beacon never got destroyed
    int maxLength = 1;
    
    //FIRST LEFT BEACON CLOSEST TO BLAST RADIUS BUT OUT OF IT
    //beacon to the left of current beacon out of it's blast radius
    
    /*
    //Instead of looping linearly to find the first beacon, BS on range
    int idx = -1;
    for(int i = beacon - 1; i >= 0; i--){
        if(pos[i] < pos[beacon] - power[beacon]){
            idx = i; 
            break;
        }
    }
    
    */
    
    int idx = findBeacon(beacon, beacons);
    if(idx != -1){
        maxLength = 1 + getMaxActivated(idx, beacons, memo);
    }
    return memo[beacon] = maxLength;
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<pair<int, int> > beacons(n);
    for(int i = 0; i < n; i++){
        //{pos, power}
        cin >> beacons[i].first >> beacons[i].second;
    }
    
    //Always remember to SORT INPUT unless stated EXPLICITLY, IF USING BINARY SEARCH ()
    sort(beacons.begin(), beacons.end());
    
    // ans = MINIMUM DESTROYED = MAKE MAXIMUM SURVIVE
    //BEACON CAN ONLY SURVIVE IF IT IS ACTIVATED
    //Give each beacon the chance to be the first one to get activated
    //Meaning all the beacon to the right of it were destroyed by the NEW BEACON
    vector<int> memo(n, -1);
    int minDestroyed = INT_MAX;
    for(int i = n - 1; i >= 0; i--){
        minDestroyed = min(minDestroyed, n - getMaxActivated(i, beacons, memo));
    }
    cout << minDestroyed << '\n';
}
