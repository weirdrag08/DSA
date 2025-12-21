class Solution {
public:

    static bool compare(const vector<string> &a, const vector<string> &b){
        if(stoi(a[1]) == stoi(b[1])){
            if(a[0] == b[0]){
                return true;
            }
            //As at the same timestamp, STATUS CHANGE IS PROCESSED FIRST, so OFFLINE SHOULD APPEAR BEFORE MESSAGE 
            else{
                return a[0] == "OFFLINE" ? true : false;
            }
        }
        return stoi(a[1]) < stoi(b[1]);
    }

    vector<int> parseMentionString(string mentionString){
        vector<int> users;
        string num = "";
        for(int i = 0; i < mentionString.size(); i++){
            char ch = mentionString[i];
            if(isdigit(ch)){
                num += ch;
            }
            else{
                if(num != ""){
                    users.push_back(stoi(num));
                    num = "";
                }
            }
        }
        //push the last user formed in nums;
        if(num != ""){
            users.push_back(stoi(num));
        }
        return users;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), compare);
        //Initially No one is offline, so they are active since timestamp 0
        vector<int> mentions(numberOfUsers, 0), activeSince(numberOfUsers, 0);
        for(int i = 0; i < events.size(); i++){
            if(events[i][0] == "MESSAGE"){
                string refer = events[i][2];
                int timeStamp = stoi(events[i][1]);
                if(refer == "ALL"){
                    // mention[0] += 1;
                    for(int i = 0; i < numberOfUsers; i++){
                        mentions[i] += 1;
                    }
                }
                else if(refer == "HERE"){
                    for(int i = 0; i < numberOfUsers; i++){
                        if(activeSince[i] <= timeStamp){
                            mentions[i] += 1;
                        }
                    }
                }
                else{
                    //processing of id's
                    vector<int> users = parseMentionString(events[i][2]);
                    for(int i : users){
                        mentions[i] += 1;
                    }
                }
            }
            else{
                int user = stoi(events[i][2]);
                int timeStamp = stoi(events[i][1]);
                activeSince[user] = timeStamp + 60;
            }
        }
        return mentions;
    }
};
