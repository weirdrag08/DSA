class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(int i = 0; i < edges.size(); i++){
            int v = edges[i][1];
            indegree[v] += 1;
        }

        //Team with indegree = 0, are the strongest teams, as there is no incoming edge towards them
        int res = -1;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                if(res == -1){
                    res = i;
                }
                else{
                    return -1;
                }
            }
        }
        return res;
    }
};
