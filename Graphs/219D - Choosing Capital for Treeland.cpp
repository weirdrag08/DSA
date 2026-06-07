#include <bits/stdc++.h>
using namespace std;

void dfs(int caller, int node, int &count, vector<vector<pair<int, bool> > > &adj){
    for(int i = 0; i < adj[node].size(); i++){
        int child = adj[node][i].first;
        bool edge = adj[node][i].second;
        if(child != caller){
            //reversal of edge required to reach child from node as there is no physical edge between them
            if(!edge){
                count += 1;
            }
            dfs(node, child, count, adj);
        }
    }
}

//ReRoot from node -> child and apply mathematical correction
void reRoot(int caller, int node, int &minReversal, vector<int> &res, vector<vector<pair<int, bool> > > &adj){
    for(int i = 0; i < adj[node].size(); i++){
        int child = adj[node][i].first;
        bool edge = adj[node][i].second;
        if(child != caller){g
            //If physical edge from node -> child, then after rerooting, for the child to be able to reach node, reversal is required, so add 1 to res[node]
            if(edge){
                res[child] = res[node] + 1;
            }
            //If edge is originally from child -> node, then the reversal value, a + 1 was already added in res[node] so that the node could reach the child. But after rerooting(making the child a root), the child will be able to get back to the node using the physical edge, requiring no reversal, so subtract -1 from res[node] 
            else{
                res[child] = res[node] - 1;
            }
            minReversal = min(minReversal, res[child]);
            reRoot(node, child, minReversal, res, adj);
        }
    }
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<vector<pair<int, bool> > > adj(n, vector<pair<int, bool>>());
    vector<int> res(n); 
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(make_pair(v - 1, true));
        adj[v - 1].push_back(make_pair(u - 1, false));
    }
    
    /*
    Rerooting DP
    1) Choose a node to be a root and evaluate the property for that node
    2) Do pre order DFS or level order BFS to ReRoot, i.e. apply mathematical correction to the property value of the root node and let the data flow in the tree without conflicts (solve subproblems before problems)
    
    */
    int count = 0;
    //Evaluate property for root(0)
    dfs(0, 0, count, adj);
    res[0] = count;
    
    //Reroot to let the data flow in the tree
    int minReversal = res[0];
    reRoot(0, 0, minReversal, res, adj);
    
    cout << minReversal << '\n';
    for(int i = 0; i < res.size(); i++){
        if(res[i] == minReversal){
            cout << i + 1 << " ";
        }
    }
}
