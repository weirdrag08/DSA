class Solution {
public:
    int minJumps(vector<int>& arr) {
        // simply a shortest path from source to dest with the edges as defined
        //{idx, distance}
        queue<pair<int, int> > q;
        vector<int> visited(arr.size(), false);
        //{val, idx}
        unordered_map<int, vector<int> > memory;
        for(int i = 0; i < arr.size(); i++){
            memory[arr[i]].push_back(i);
        }
        q.push(make_pair(0, 0));
        visited[0] = true;
        while(!q.empty()){
            pair<int, int> front = q.front();
            q.pop();
            int idx = front.first, dist = front.second;
           
            // Check if reached last index
            if(idx == arr.size() - 1){
                return dist;
            }

            // 3 types of edges
            //i -> i + 1
            if(idx + 1 < arr.size() && !visited[idx + 1]){
                q.push(make_pair(idx + 1, dist + 1));
                visited[idx + 1] = true;
            }

            //i -> i - 1
            if(idx - 1 >= 0 && !visited[idx - 1]){
                q.push(make_pair(idx - 1, dist + 1));
                visited[idx - 1] = true;
            }

            //i -> j iff (arr[i] == arr[j])
            if(memory.count(arr[idx]) > 0){
                for(int i : memory[arr[idx]]){
                    if(idx != i && !visited[i]){
                        q.push(make_pair(i, dist + 1));
                        visited[i] = true;
                    }
                }
                //Important Optimisation
                memory.erase(arr[idx]);
            }
        }
        return -1;
    }
};
