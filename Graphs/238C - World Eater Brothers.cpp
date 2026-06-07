#include <bits/stdc++.h>
using namespace std;

void dfs(int caller, int node, int ignoreU, int ignoreV, int &count, vector<vector<pair<int, bool> > > &adj){
    for(int i = 0; i < adj[node].size(); i++){
        int child = adj[node][i].first;
        bool edge = adj[node][i].second;
        if(node == ignoreU && child == ignoreV){
            continue;
        }
        if(child != caller){
            //reversal of edge required to reach child from node as there is no physical edge between them
            if(!edge){
                count += 1;
            }
            dfs(node, child, ignoreU, ignoreV, count, adj);
        }
    }
}

//ReRoot from node -> child and apply mathematical correction
void reRoot(int caller, int node, int ignoreU, int ignoreV, int &minRev, int res, vector<vector<pair<int, bool> > > &adj){
    for(int i = 0; i < adj[node].size(); i++){
        int child = adj[node][i].first;
        bool edge = adj[node][i].second;
        if(node == ignoreU && child == ignoreV){
            continue;
        }
        if(child != caller){
            //If physical edge from node -> child, then after rerooting, for the child to be able to reach node, reversal is required, so add 1 to res[node]
            int resChild = 0;
            if(edge){
                resChild = res + 1;
            }
            //If edge is originally from child -> node, then the reversal value, a + 1 was already added in res[node] so that the node could reach the child. But after rerooting(making the child a root), the child will be able to get back to the node using the physical edge, requiring no reversal, so subtract -1 from res[node] 
            else{
                resChild = res - 1;
            }
            minRev = min(minRev, resChild);
            reRoot(node, child, ignoreU, ignoreV, minRev, resChild, adj);
        }
    }
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<vector<int> > edges(n - 1, vector<int>(2));
    vector<vector<pair<int, bool> > > adj(n, vector<pair<int, bool>>());
     
    
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        edges[i][0] = u - 1, edges[i][1] = v - 1;
        adj[u - 1].push_back(make_pair(v - 1, true));
        adj[v - 1].push_back(make_pair(u - 1, false));
    }
    
    //O(N^2)
    int ans = INT_MAX;
    //If n == 1, only 1 node, so no edge reversal is required
    if(n > 1){
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            int countU = 0, countV = 0;
            // vector<int> resU, resV;
            
            //Evaluating property for root(u)
            dfs(u, u, u, v, countU, adj);
            //Evaluating property for root(v)
            dfs(v, v, v, u, countV, adj);
            
            
            int minRevU = countU, minRevV = countV; 
            reRoot(u, u, u, v, minRevU, countU, adj);
            reRoot(v, v, v, u, minRevV, countV, adj);
            
            
            ans = min(ans, minRevU + minRevV);
        }
        cout << ans << '\n';
    }
    else{
        cout << 0 << '\n';
    }
}
