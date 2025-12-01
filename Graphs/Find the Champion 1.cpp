class Solution {
public:

    int findChampion(vector<vector<int>>& grid) {
        vector<int> indegree(grid.size());

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(i != j && grid[i][j] == 1){
                    indegree[j] += 1;
                }
            }
        }

        //team with indegree = 0, is the strongest team as no incoming edge
        for(int i = 0; i < grid.size(); i++){
            if(indegree[i] == 0){
                return i;
            }
        }
        return 0;
    }
};
