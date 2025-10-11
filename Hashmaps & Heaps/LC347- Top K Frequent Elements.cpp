class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //frq[num] = frequency
        unordered_map<int, int> frq;
        //pq element = {frequency, num}
        priority_queue<pair<int, int> > pq;

        for(int i = 0; i < nums.size(); i++){
            frq[nums[i]] += 1;
        }

        for(auto p : frq){
            //PQ element = {frequency, element}
            //Sort by max frequency, if frequency tied, sort by bigger element
            pq.emplace(p.second, p.first);
        }

        vector<int> res;
        while(k--){
            auto p = pq.top();
            pq.pop();

            //insert the most frequent element in order
            //p = {frequency, num}
            res.push_back(p.second);
        }
    return res;
    }
};
