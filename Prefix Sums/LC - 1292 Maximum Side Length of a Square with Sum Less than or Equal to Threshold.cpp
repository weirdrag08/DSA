class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int> > prefix(m, mat[0]);

        //col prefix
        for(int j = 0; j < n; j++){
            for(int i = 1; i < m; i++){
                prefix[i][j] = prefix[i - 1][j] + mat[i][j];
            }
        }

        //row prefix
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                prefix[i][j] += prefix[i][j - 1];
            }
        }

        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int side = min(m - i, n - j) - 1;
                for(int k = 0; k <= side; k++){
                    int rowEnd = i + k, colEnd = j + k;
                    int sum = prefix[rowEnd][colEnd] - (i > 0 ? prefix[i - 1][colEnd] : 0) - (j > 0 ? prefix[rowEnd][j - 1] : 0) + (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
                    if(sum <= threshold){
                        res = max(res, k + 1);
                    }
                    //sum over threshold with side = k, so for sides inRange [k + 1, k + 2....side], sum will be even more 
                    else{
                        break;
                    }
                }
            }
        }
        return res;
    }
};
