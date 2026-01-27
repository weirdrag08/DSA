class Solution {
public:

    int djikstra(int n, vector<vector<pair<int, int> > > &adj1, vector<vector<pair<int, int> > > &adj2){
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        vector<int> distance(n, INT_MAX);
        pq.emplace(0, 0);
        // distance[0][0] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second, dist = top.first;
            // cout << node << " " << dist << " " << revUsed << '\n';
            //sub optimal distance, so skipped, as djikstra guarantees that the first occurence of the node popped will be at the shortest distance
            if(distance[node] != INT_MAX){
                continue;
            }

            //Optimal distance, as distance of this node from source was previously INF, so first occurence found
            distance[node] = dist;

            //Reached n - 1 for the first time
            if(node == n - 1){
                return distance[node];
            }

            for(int i = 0; i < adj1[node].size(); i++){
                int neighbour = adj1[node][i].first, weight = adj1[node][i].second;
                //Only push nodes whose shortest path is not found
                if(distance[neighbour] == INT_MAX){
                    pq.emplace(dist + weight, neighbour);
                }
            }
            // Each node has it's own reversal switch, activate it once you reach a new node, to simulate reversed edges traversal
            for(int i = 0; i < adj2[node].size(); i++){
                int neighbour = adj2[node][i].first, weight = adj2[node][i].second;
                if(distance[neighbour] == INT_MAX){
                    pq.emplace(dist + 2 * weight, neighbour);
                }
            }
        }
        return distance[n - 1] == INT_MAX ? -1 : distance[n - 1];
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
