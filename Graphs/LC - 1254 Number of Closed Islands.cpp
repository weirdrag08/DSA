class Solution {
public:

    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<bool> > &visited, vector<vector<int> > &grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 1 || visited[i][j]){
            return;
        }
        visited[i][j] = true;
        for(int k = 0; k < 4; k++){
            int nr = i + dx[k], nc = j + dy[k];
            dfs(nr, nc, visited, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                        dfs(i, j, visited, grid);
                    }
                }
            }
        }

        int res = 0;
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(grid[i][j] == 0 && !visited[i][j]){
                    dfs(i, j, visited, grid);
                    res += 1;
                }
            }
        }
        return res;
    }
};
