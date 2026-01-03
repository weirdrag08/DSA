class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, vector<int>> frq;
        sort(hand.begin(), hand.end());
        for(int i = 0; i < hand.size(); i++){
            frq[hand[i]].push_back(i);
        }
        for(int i = 0; i < hand.size(); i++){
            if(hand[i] != -1){
                int element = hand[i], currGroup = 1;
                hand[i] = -1;
                // cout << "start: " << element << " ";
                while(currGroup < groupSize){
                    if(frq.count(element + 1) > 0){
                        int idx = frq[element + 1].back();
                        hand[idx] = -1;
                        frq[element + 1].pop_back();
                        if(frq[element + 1].size() == 0){
                            frq.erase(element + 1);
                        }
                        currGroup += 1;
                        element += 1;
                        // cout << element << " ";
                    }
                    else{
                        return false;
                    }
                }
                // cout << "state: ";
                // for(int i : hand){
                //     cout << i << " ";
                // }
                // cout << '\n';
            }
        }
        return true;
    }
};
