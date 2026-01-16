class Solution {
public:
    
    const int MOD = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(vFences.begin(), vFences.end());
        sort(hFences.begin(), hFences.end());
        unordered_set<int> vFrq;
        vFrq.insert(n - 1);
        for(int i = 0; i < vFences.size(); i++){
            for(int j = i + 1; j < vFences.size(); j++){
                int curr = vFences[i], next = vFences[j];
                vFrq.insert(next - curr);
            }
            vFrq.insert(vFences[i] - 1);
            vFrq.insert(n - vFences[i]);
        }
        
        int maxSide = -1;
        if(vFrq.count(m - 1) > 0 && m - 1 > maxSide){
            maxSide = m - 1;
        }
        for(int i = 0; i < hFences.size(); i++){
            for(int j = i + 1; j < hFences.size(); j++){
                int curr = hFences[i], next = hFences[j];
                if(vFrq.count(next - curr) > 0 && next - curr > maxSide){
                    maxSide = next - curr;
                }
            }
            if(vFrq.count(hFences[i] - 1) > 0 && hFences[i] - 1 > maxSide){
                maxSide = hFences[i] - 1;
            }
            if(vFrq.count(m - hFences[i]) > 0 && m - hFences[i] > maxSide){
                maxSide = m - hFences[i];
            }
        }
        if(maxSide == -1){
            return -1;
        }
        else{
            return (1LL * maxSide * maxSide) % MOD;
        }
    }
};
