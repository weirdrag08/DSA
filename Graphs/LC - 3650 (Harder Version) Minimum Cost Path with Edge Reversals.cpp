class Solution {
public:

    int djikstra(int n, vector<vector<pair<int, int> > > &adj1, vector<vector<pair<int, int> > > &adj2){
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
        vector<vector<int> > distance(n, vector<int>(2, INT_MAX));
        pq.emplace(0, make_pair(0, 0));
        // distance[0][0] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second.first, dist = top.first, revUsed = top.second.second;
            // cout << node << " " << dist << " " << revUsed << '\n';
            //sub optimal distance, so skipped, as djikstra guarantees that the first occurence of the node popped will be at the shortest distance
            if(distance[node][revUsed] != INT_MAX){
                continue;
            }

            //Optimal distance, as distance of this node from source was previously INF, so first occurence found
            distance[node][revUsed] = dist;

            for(int i = 0; i < adj1[node].size(); i++){
                int neighbour = adj1[node][i].first, weight = adj1[node][i].second;
                //Only push whose shortest path is not found
                if(distance[neighbour][revUsed] == INT_MAX){
                    pq.emplace(dist + weight, make_pair(neighbour, revUsed));
                }
            }
            // If reversal switch hasn't been used yet till the current node, you have the option to reverse here
            if(revUsed < 1){
                for(int i = 0; i < adj2[node].size(); i++){
                    int neighbour = adj2[node][i].first, weight = adj2[node][i].second;
                    if(distance[neighbour][revUsed + 1] == INT_MAX){
                        pq.emplace(dist + 2 * weight, make_pair(neighbour, revUsed + 1));
                    }
                }
            }
        }
        int res = min(distance[n - 1][0], distance[n - 1][1]);
        return res == INT_MAX ? -1 : res;
    }

    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int> > > adj1(n), adj2(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj1[u].push_back(make_pair(v, w));
            adj2[v].push_back(make_pair(u, w));
        }
        return djikstra(n, adj1, adj2);
    }
};
