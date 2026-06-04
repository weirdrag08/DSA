class Solution {
public:

    bool dfs(int parent, int src, int &time, int &apples, vector<bool> &hasApple, vector<vector<int> > &adj){
        bool collected = false;

        //collect apple at current node if any
        if(hasApple[src]){
            apples -= 1;
            collected = true;
        }

        //Keep exploring only if apples left
        if(apples > 0){
            bool collectedInSubtree = false;
            for(int i = 0; i < adj[src].size(); i++){
                int node = adj[src][i]; 
                if(parent != node){
                     collectedInSubtree = dfs(src, node, time, apples, hasApple, adj);
                     //Add traversal time for only those subtrees that resulted in the collection of the apple
                     //those subtrees that didn't have any apple in them, must not be included in the total time, but to find out if they have any apple or not, they must be traversed.
                     //BUT TIME WILL ONLY BE ADDED IFF ANY APPLE WAS COLLECTED
                    if(collectedInSubtree){
                        //pre & post call time addition
                        time += 2;
                    }
                    collected |= collectedInSubtree;
                }
            }
        }
        return collected;  
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int> > adj(n, vector<int>());
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int time = 0, apples = 0;
        for(bool b : hasApple){
            if(b){
                apples += 1;
            }
        }
        bool res = dfs(0, 0, time, apples, hasApple, adj);
        return time;
    }
};
