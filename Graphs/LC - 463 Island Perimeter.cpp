/*
// SIMPLE OBSERVATION BASED METHOD TO SOLVE
class Solution {
public:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    bool isValid(int r, int c, vector<vector<int> > &grid){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()){
            return false;
        }
        return true;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        int nr = i + dx[k], nc = j + dy[k];
                        bool valid = isValid(nr, nc, grid);
                        if(!valid || valid && grid[nr][nc] == 0){
                            perimeter += 1;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};



*/

// DFS Solution
class Solution {
public:

    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, vector<vector<bool> > &visited, vector<vector<int> > &grid){
        //water or boundary cell
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return false;
        }
        return true;
    }
    int dfs(int i, int j, vector<vector<bool> > &visited, vector<vector<int> > &grid){
        visited[i][j] = true;
        int perimeter = 0;
        for(int k = 0; k < 4; k++){
            int nr = i + dx[k], nc = j + dy[k];
            bool valid = isValid(nr, nc, visited, grid);
            if(!valid){
                perimeter += 1;
            }
            if(valid && !visited[nr][nc]){
                perimeter += dfs(nr, nc, visited, grid);
            }
        }
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //only 1 island, so only 1cc, directly return the value of perimeter from here
                if(grid[i][j] == 1 && !visited[i][j]){
                    return dfs(i, j, visited, grid);
                }
            }
        }
        return 0;
    }
};
