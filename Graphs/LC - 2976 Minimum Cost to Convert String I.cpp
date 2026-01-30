class Solution {
public:
    const long long INF = 2e12;

    void djikstra(char u, vector<vector<long long> > &memory, vector<vector<pair<char, int> > > &adj){
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char> > > pq;
        pq.emplace(0, u);
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            long long dist = top.first;
            char node = top.second;
            
            //sub optimal occurence
            if(memory[u - 'a'][node - 'a'] != INF){
                continue;
            }
            
            memory[u - 'a'][node - 'a'] = dist;
            
            //IMPORTANT - Never run Multi Djikstra with the 'found destination' condition
            //LET THE DJIKSTRA RUN COMPLETE FOR THE CURRENT SOURCE
            //i.e. let djikstra evaluate the WHOLE ROW, which is distance[source][*] 
            //AS djikstra is a SSSP algo, which guarantees to find the shortest path from a single source to all other nodes
            // if(node == v){
            //     return;
            // }

            for(int i = 0; i < adj[node - 'a'].size(); i++){
                int v = adj[node - 'a'][i].first, weight = adj[node - 'a'][i].second;
                if(memory[u - 'a'][v - 'a'] == INF){
                    pq.emplace(dist + 1LL * weight, v);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<char, int> > > adj(26, vector<pair<char, int> >());
        for(int i = 0; i < original.size(); i++){
            char u = original[i], v = changed[i];
            int w = cost[i];
            adj[u - 'a'].emplace_back(v, w); 
        }
        vector<vector<long long> > memory(26, vector<long long>(26, INF));

        long long sum = 0;
        vector<bool> computed(26, false);
        for(int i = 0; i < source.size(); i++){
            char u = source[i], v = target[i];
            if(!computed[u - 'a']){
                djikstra(u, memory, adj);
                computed[u - 'a'] = true;
            }
            if(memory[u - 'a'][v - 'a'] == INF){
                return -1;
            }
            sum += memory[u - 'a'][v - 'a'];
        }
        return sum;
    }
};
