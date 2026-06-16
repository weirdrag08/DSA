class Solution {
public:

    int getMaxDPOptimised(int num, int len, string &floor, vector<int> &pf){
        int n = floor.size(), carpUsed = 0;
        vector<int> curr(n + 1, 0), next(n + 1, 0);
        for(int i = num - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int op1 = 0, op2 = 0;
                int l = j - 1, r = (j + len - 1) >= (int) pf.size() ? (int) pf.size() - 1 : j + len - 1;
                op1 = (l < 0 ? pf[r] : pf[r] - pf[l]) + next[r + 1];
                op2 = curr[j + 1];
                curr[j] = max(op1, op2);
            }
            swap(curr, next);
        }
        return next[0];
    }

    int getMax(int idx, int num, int &len, string &floor, vector<int> &pf, vector<vector<int> > &memo){
        if(idx >= floor.size()){
            return 0;
        }

        if(memo[idx][num] != -1){
            return memo[idx][num];
        }

        //options = cover or not
        int op1 = 0, op2 = 0;
        if(num > 0){
            int l = idx - 1, r = (idx + len - 1 >= (int) pf.size() ? (int) pf.size() - 1 : idx + len - 1);
            op1 = (l < 0 ? pf[r] : pf[r] - pf[l]) + getMax(r + 1, num - 1, len, floor, pf, memo);
        }
        op2 = getMax(idx + 1, num, len, floor, pf, memo);
        return memo[idx][num] = max(op1, op2);
    }

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        vector<int> pf(floor.size(), 0);
        pf[0] = floor[0] == '1' ? 1 : 0;
        for(int i = 1; i < pf.size(); i++){
            int white = floor[i] == '1' ? 1 : 0;
            pf[i] = pf[i - 1] + white;
        }
        int totalWhite = pf[pf.size() - 1];
        // vector<vector<int> > memo(floor.size(), vector<int>(numCarpets + 1, -1));
        // return totalWhite - getMax(0, numCarpets, carpetLen, floor, pf, memo);
        return totalWhite - getMaxDPOptimised(numCarpets, carpetLen, floor, pf);
    }
};
