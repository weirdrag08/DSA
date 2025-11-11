 bool compare(const pair<long long, int> &a, const pair<long long, int> &b){
      if(a.first == b.first){
          return a.second < b.second;
      }
      return a.first > b.first;
  }
class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<long long, int> > diff(n, {0, -1});
        for(int i = 0; i < n; i++){
            diff[i].first = 1LL * abs(arr[i] - brr[i]);
            diff[i].second = i;
        }
        sort(diff.begin(), diff.end(), compare);
        long long res = 0;
        int aCount = 0, bCount = 0;
        for(int i = 0; i < n; i++){
            int idx = diff[i].second;
            if(brr[idx] < arr[idx]){
                if(aCount < x){
                    res += arr[idx];
                    aCount += 1;
                }
                else{
                    res += brr[idx];
                    bCount += 1;
                }
            }
            else{
                if(bCount < y){
                    res += brr[idx];
                    bCount += 1;
                }
                else{
                    res += arr[idx];
                    aCount += 1;
                }
            }
        }
        return res;
    }
};
