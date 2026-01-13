class DSU{
    public:
    int n;
    vector<int> parent, size;

    DSU(int n){
        parent = vector<int>(n, 0);
        size = vector<int>(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int Find(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = Find(parent[u]);
    }

    void Union(int a, int b){
        int parA = Find(a), parB = Find(b);
        if(parA != parB){
            if(size[parA] >= size[parB]){
                parent[parB] = parA;
                size[parA] += size[parB];
            }
            else{
                parent[parA] = parB;
                size[parB] += size[parA];
            }
        }
    }
};

class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU ds(n);
        //Add an edge between u-v, making them part of a single component
        for(int i = 0; i < edges.size(); i++){
            ds.Union(edges[i][0], edges[i][1]);
        }
        //source & destination have the same ultimate parent, which means they are in the same component
        if(ds.Find(source) == ds.Find(destination)){
            return true;
        }
        //Different component so not reachable
        else{
            return false;
        }
    }
};
