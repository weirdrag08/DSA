class Solution {
public:

    int bfs(string beginWord, int endIdx, vector<string> &wordList, unordered_map<string, vector<int> > &memory){
        queue<pair<int, int> > q;
        vector<bool> visited(wordList.size() + 1, false);

        q.emplace(0, 1);
        visited[0] = true;

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int node = front.first, dist = front.second;

            if(node - 1 == endIdx){
                return dist;
            }
            string word = (node == 0 ? beginWord : wordList[node - 1]);
            for(int i = 0; i < word.size(); i++){
                char og = word[i];
                word[i] = '*';
                for(int j = 0; j < memory[word].size(); j++){
                    int neighbour = memory[word][j];
                    if(!visited[neighbour]){
                        q.emplace(neighbour, dist + 1);
                        visited[neighbour] = true;
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<int> > memory;
        int endIdx = -1;
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == endWord){
                endIdx = i;
            }
            for(int j = 0; j < wordList[i].size(); j++){
                char og = wordList[i][j];
                wordList[i][j] = '*';
                memory[wordList[i]].push_back(i + 1);
                wordList[i][j] = og;
            }
        }
        for(int j = 0; j < beginWord.size(); j++){
            char og = beginWord[j];
            beginWord[j] = '*';
            memory[beginWord].push_back(0);  
            beginWord[j] = og;
        }

        if(endIdx == -1){
            return 0;
        }
        
        return bfs(beginWord, endIdx, wordList, memory);
    }
};
