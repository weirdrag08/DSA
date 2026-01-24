class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > rPrefix(m, vector<int>(n, 0)), cPrefix(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //Row wise Prefix
                if(j == 0){
                    rPrefix[i][j] = grid[i][j];
                } 
                else{
                    rPrefix[i][j] = grid[i][j] + rPrefix[i][j - 1];
                }
                //Column wise Prefix
                if(i == 0){
                    cPrefix[i][j] = grid[i][j];
                }
                else{
                    cPrefix[i][j] = grid[i][j] + cPrefix[i - 1][j];
                }
            }
        }
        int res = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int side = min(m - i, n - j);
                for(int t = 1; t < side; t++){
                    int rowEnd = i + t, colEnd = j + t;
                    bool magicSquare = true;
                    //check rows
                    int rSum = 0, cSum = 0, d1Sum = 0, d2Sum = 0;
                    for(int l = i; l <= rowEnd; l++){
                        if(j == 0){
                            if(rSum == 0){
                                rSum = rPrefix[l][colEnd];
                            }
                            else{
                                if(rSum != rPrefix[l][colEnd]){
                                    magicSquare = false;
                                    break;
                                }
                            }
                        }
                        else{
                            if(rSum == 0){
                                rSum = rPrefix[l][colEnd] - rPrefix[l][j - 1];
                            }
                            else{
                                if(rSum != rPrefix[l][colEnd] - rPrefix[l][j - 1]){
                                    magicSquare = false;
                                    break;
                                }
                            }
                        }
                    }

                    if(!magicSquare){
                        continue;
                    }

                    //check cols
                    for(int l = j; l <= colEnd; l++){
                        if(i == 0){
                            if(cSum == 0){
                                cSum = cPrefix[rowEnd][l];
                            }
                            else{
                                if(cSum != cPrefix[rowEnd][l]){
                                    //make possibility false early and break;
                                    magicSquare = false;
                                    break;
                                }
                            }
                        }
                        else{
                            if(cSum == 0){
                                cSum = cPrefix[rowEnd][l] - cPrefix[i - 1][l];
                            }
                            else{
                                if(cSum != cPrefix[rowEnd][l] - cPrefix[i - 1][l]){
                                    magicSquare = false;
                                    break;
                                }
                            }
                        }
                    }
                    if(!magicSquare){
                        continue;
                    }

                    //Check diagonals
                    for(int a = i, b = j, c = i, d = colEnd; a <= rowEnd && b <= colEnd; a++, b++, c++, d--){
                        //d1 sum
                        d1Sum += grid[a][b];
                        //d2 sum
                        d2Sum += grid[c][d];
                    }

                    //All properties satisfied
                    if(rSum == cSum && cSum == d1Sum && d1Sum == d2Sum){
                        res = max(res, t + 1);
                    }
                }
            }
        }
        return res;
    }
};
