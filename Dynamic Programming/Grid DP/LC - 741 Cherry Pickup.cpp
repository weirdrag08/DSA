class Solution {
public:
    const int nINF = -1e9;
    pair<bool, int> pickup(int r, int c, bool journeyUp, vector<vector<int> > &grid){
        //Invalid Cells
        if(r < 0 || c < 0 || r >= (int) grid.size() || c >= (int) grid.size() || grid[r][c] == -1){
            return make_pair(false, 0);
        }
        //Base Case
        if(r == 0 && c == 0 && journeyUp){
            return make_pair(true, 0);
        }

        //Change Direction
        if(r == grid.size() - 1 && c == grid.size() - 1 && !journeyUp){
            journeyUp = true;
        }
        //LEVEL = each cell
        /*OPTIONS
        journeyUp = false, {down, right}
        journeyUp = true, {up, left}
        */
        pair<bool, int> cherries = {false, 0};
        bool hasCherry = grid[r][c] == 1 ? true : false;

        //take cherry
        if(hasCherry){
            grid[r][c] = 0;
        }
        if(journeyUp == false){
            pair<bool, int> down = {false, 0}, right = {false, 0};
            down = pickup(r + 1, c, journeyUp, grid);
            right = pickup(r, c + 1, journeyUp, grid);
            cherries.first = down.first || right.first;
            cherries.second = (hasCherry ? 1 : 0) + max(down.first ? down.second : 0, right.first ? right.second : 0);
        }
        else{
            pair<bool, int> up = {false, 0}, left = {false, 0};
            up = pickup(r - 1, c, journeyUp, grid);
            left = pickup(r, c - 1,  journeyUp, grid);
            cherries.first = up.first || left.first;
            cherries.second = (hasCherry ? 1 : 0) + max(up.first ? up.second : 0, left.first ? left.second : 0);
        }
        //backtrack to previous state
        if(hasCherry){
            grid[r][c] = 1; 
        }
        return cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1){
            return grid[0][0] == 1 ? 1 : 0;
        }
        auto res = pickup(0, 0, false, grid);
        return res.first ? res.second : 0;
    }
};
