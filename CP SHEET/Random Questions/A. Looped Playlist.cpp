#include <bits/stdc++.h>
using namespace std;

pair<int, pair<long long, long long> > shortestSequenceToMakeHappy(long long happy, vector<int> &songs){
    long long mood = 0;
    //{starting idx, {count of songs, mood}}
    pair<int, pair<long long, long long> > res = {0, {LLONG_MAX, LLONG_MAX}};
    for(int i = 0, j = 0; i < songs.size(); i++){
        //Listen songs till the mood >= happy
        mood += 1LL * songs[i];
        // cout << i << " ";
        //If mood VALID(mood >= happy), remove songs till no more removal possible (mood - songs[j]>= happy)
        while(mood - songs[j] >= happy){
            // cout << j << " " << mood << '\n';
            mood -= songs[j];
            j++;
            //shorter sequence that is valid (mood >= happy), update result
            if((i - j + 1) < res.second.first){
                res.first = j;
                res.second.first = i - j + 1;
                res.second.second = mood;
            }
            //current sequence size = best sequence found till now, but better mood score
            if(i - j + 1 == res.second.first && mood > res.second.second){
                res.first = j;
                res.second.first = i - j + 1;
                res.second.second = mood;
            }
        }
    }
    
    //No sequence found that makes the mood >= happy, repeat the 
    // if(res.second != LLONG_MAX){
        
    // }
    
    // //sum[idx, idx + length - 1]
    // long long sum = 0;
    // for(int i = res.first; i <= res.first + res.second - 1; i++){
    //     sum += 1LL * songs[i];
    // }
    
    // // Happiness can't be achieved by listening to that shortest valid sequence once, loop the shortest valid sequence.
    // //If happiness wasn't achieved, that means the sum(0, songs.siz() - 1) < happy, i.e. sum of all songs < happy, repeat playlist
    // long long repeat = 0, remaining = 0;
    // if(sum < happy){
    //     repeat = happy / sum;
    //     remaining = happy % sum;
    //     long long count = 0;
    //     for(int i = res.first; i <= res.first + res.second - 1; i++){
    //         if(remaining - songs[i] > 0){
    //             remaining - songs[i];
    //             count++;
    //         }
    //     }
    //     res.second = res.second * repeat + count;
    // }
    // return res;
    return res;
}



int main() {
	// your code goes here
    int n;
    long long happy;
    cin >> n >> happy;
    vector<int> songs(n);
    for(int i = 0; i < n; i++){
        cin >> songs[i];
    }
    auto p = shortestSequenceToMakeHappy(happy, songs);
    cout << p.first << " " << p.second.first << " " << p.second.second << '\n';
}
