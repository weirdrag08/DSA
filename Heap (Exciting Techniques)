class Solution {
public:
        //So 2 types of orderings present, and priority switches based on condition
        /* IMPORTANT - The KEY recognition test
        “Can two elements FLIP their RELATIVE PRIORITY over time without changing their own values?”
        If YES → incompatible → multiple heaps required
        If NO → compatible → one comparator is enough

        If you see two entities switching their priorities as the time pass, which is whatever initial order they were
        assigned with, needs to be changed, without actually changing/mutating either entity value, then 2 comparators are required.

        SORTING based on multiple params but only 1 comparator, if it assigns an order, that order will never change with the execution of the program, if the entities being sorted are not being modified, but if their order/ priority gets changed, then 2 comparators are required, meaning 2 sorting or 2 heaps. One for each type of ordering.
        */ 
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //Among rooms present in free pq, the one with the smallest room no. gets allotted
        priority_queue<int, vector<int>, greater<int> > free;
        //Among rooms present in busy pq, earliest {freeAt, roomNo} gets alloted 
        priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > busy;
        vector<int> res(n, 0);
        //Initially all rooms are available
        for(int i = 0; i < n; i++){
            free.push(i);
        }

        //sort meetings based on increasing order of start times to schedule in the order they appear. 
        sort(meetings.begin(), meetings.end());

        for(int i = 0; i < meetings.size(); i++){
            int start = meetings[i][0], end = meetings[i][1];
            int meetingLength = end - start;


            //Check all the rooms that are in the busy pq, but are free at the start of meeting[i]
            //Push them back into the free pq, as they are available
            while(!busy.empty() && busy.top().first <= start){
                int room = busy.top().second;
                busy.pop();
                free.push(room);
            }

            //Above while loop updated the status of all the free rooms at the moment when meetings[i] is about to start
            //Assign the smallest room no, i.e. free.top();
            if(!free.empty()){
                int room = free.top();
                free.pop();

                //Record the count
                res[room] += 1;

                //Push back in the busy pq
                busy.emplace(start + meetingLength, room);
            }
            //Even after updation, no free room available, then provide the room that becomes free at the earliest possible time in the busy pq
            else{
                auto top = busy.top();
                busy.pop();
                
                res[top.second] += 1;
                busy.emplace(max(top.first, 1LL * start) + meetingLength, top.second);
            }
        }
        int room = 0, maxMeetings = 0;
        for(int i = 0; i < n; i++){
            if(res[i] > maxMeetings){
                maxMeetings = res[i];
                room = i;
            }
        }
        return room;
    }
};
