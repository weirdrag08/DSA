class Solution {
public:
    bool bfs(int source, vector<bool> &visited, vector<int> &arr){
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();

            if(arr[front] == 0){
                return true;
            }

            int forwardIdx = front + arr[front], backwardIdx = front - arr[front];
            if(forwardIdx < arr.size() && !visited[forwardIdx]){
                q.push(forwardIdx);
                visited[forwardIdx] = true;
            }
            if(backwardIdx >= 0 && !visited[backwardIdx]){
                q.push(backwardIdx);
                visited[backwardIdx] = true;
            }
        }
        return false;
    }

    bool dfs(int source, vector<bool> &visited, vector<int> &arr){
        //invalid jumps
        if(source < 0 || source >= arr.size() || visited[source]){
            return false;
        }
        visited[source] = true;
        if(arr[source] == 0){
            return true;
        }
        bool forward = false, backward = false;
        forward = dfs(source + arr[source], visited, arr);
        backward = dfs(source - arr[source], visited, arr);
        return forward || backward;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        // return dfs(start, visited, arr);
        return bfs(start, visited, arr);
    }
};
