class DSU{
    public:
    int n;
    vector<int> parent, size;

    DSU(int n){
        parent = vector<int>(n, 0);
        size = vector<int>(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void Union(int u, int v){
        int a = find(u), b = find(v);
        if(a != b){
            if(size[a] >= size[b]){
                parent[b] = a;
                size[a] += size[b]; 
            }
            else{
                parent[a] = b;
                size[b] += size[a];
            }
        }
    }
};

/*
If they would have asked about the first edge in the input that was redudant, processing should be done from the right.
1
| \
|  \
2---3

edges = [[1,2], [1,3], [2,3]]

processing left -> right, gives [2, 3] {last edge in the input that introduced the cycle}
processing right -> left, gives [1, 2] {first edge in the input that introduced the cycle}

DSU detects “this edge is unnecessary given everything before it”

“everything before it” depends on direction

Change direction → change meaning of “before”
*/

class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU ds(1001);
        vector<int> res;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            if(ds.find(u) == ds.find(v)){
                res.push_back(u);
                res.push_back(v);
                break;
            }
            else{
                ds.Union(u, v);
            }
        }
        return res;
    }
};
