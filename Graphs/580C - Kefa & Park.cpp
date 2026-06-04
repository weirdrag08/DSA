#include <bits/stdc++.h>
using namespace std;

/*
1) In CF questions TREES presented as a GRAPH, treat edges as undirected ALWAYS
2) If a graph is a MST or given a tree (acyclic and connected property), DON'T USE VISITED array. Just track parent, call on neighbours EXCEPT the edge which connects to parent.
(ACYCLIC property of TREE guarantees there is only 1 way to reach a node, through it's parent, only cycles provides more than 1 way to reach a node other than a parent, where VISITED is needed)

*/

int dfs(int parent, int src, int m, int ogM, vector<bool> &cats, vector<vector<int> > &adj){
    // if cat on current node, reduce m, otherwise set it to default
    m = cats[src] ? m - 1 : ogM;
    
    //invalid case
    if(m < 0){
        return 0;
    }
    
    //base case
    if(adj[src].size() == 1 && parent != src){
        return 1;
    }
    
    int count = 0;
    
    for(int i = 0; i < adj[src].size(); i++){
        int node = adj[src][i];
        if(node != parent){
            count += dfs(src, node, m, ogM, cats, adj);
        }
    }
    return count;
}

int main() {
	// your code goes here
	int n, m;
	cin >> n >> m;
	vector<bool> cats(n);
	vector<vector<int> > adj(n, vector<int>());
	for(int i = 0; i < n; i++){
	    int cat;
	    cin >> cat;
	    cats[i] = (bool) cat;
	}
	
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    
    cout << dfs(0, 0, m, m, cats, adj) << '\n';
}
