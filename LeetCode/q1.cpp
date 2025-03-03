//2054. Two Best Non-Overlapping Events

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),[] (const vector <int>& a,const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> maxValues(n,0);
        vector<int> endTimes(n,0);

        for(int i = 0; i < n; ++i) {
            endTimes[i] = events[i][1];
        }
        maxValues[0] = events[0][2];
        for(int i = 1; i < n; ++i){
            maxValues[i] = max(maxValues[i - 1], events[i][2]);
        }
        int maxResult = 0;

        for (int i = 0; i < n; ++i) {
            int currentStartTime = events[i][0];
            int currentValue = events[i][2];

            int val = upper_bound(endTimes.begin(), endTimes.end(), currentStartTime - 1) - endTimes.begin() - 1;

            if(val >= 0) {
                maxResult = max(maxResult, currentValue + maxValues[val]);
            }else {
              maxResult = max(maxResult, currentValue );

            }
        }
        return maxResult;
    }
};