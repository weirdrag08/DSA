class Solution {
public:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    bool valid(int x, int y, int row, int col, vector<vector<bool> > &visited){
        if(x < 0 || x >= row || y < 0 || y >= col || visited[x][y]){
            return false;
        }
        return true;
    }

    bool bfs(int row, int col, int day, map<pair<int, int>, int > &memory){
        queue<pair<int, int> > q;
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for(int i = 0; i < col; i++){
           if(memory.count(make_pair(0, i)) == 0 || memory[make_pair(0, i)] > day){
                q.push(make_pair(0, i));
                visited[0][i] = true;
           }
        }
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int r = front.first, c = front.second;
            if(r == row - 1){
                return true;
            }
            for(int i = 0; i < 4; i++){
                int x = r + dx[i], y = c + dy[i];
                if(valid(x, y, row, col, visited)){
                    if(memory.count(make_pair(x, y)) == 0 || memory[make_pair(x, y)] > day){
                        q.push(make_pair(x, y));
                        visited[x][y] = true;
                    }
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        map<pair<int, int>, int > memory;
        //1 based indexing in cells, so (r - 1, c - 1) to make it 0 based
        for(int i = 0; i < cells.size(); i++){
            memory[make_pair(cells[i][0] - 1, cells[i][1] - 1)] = i;
        }
        int l = 0, r = cells.size() - 1, res = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            bool cross = bfs(row, col, mid, memory);
            if(cross){
                //days are also 1 based, so ith day represent i + 1th day
                res = mid + 1;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return res;
    }
};
