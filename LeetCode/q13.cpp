//1792. Maximum Average Pass Ratio

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for(auto& c : classes) {
            int pass = c[0],total = c[1];
            double delta = (double)(pass + 1) / (total + 1) - (double)pass / total;
            maxHeap.push({delta, {pass, total}});
        }
        while (extraStudents--) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int pass = top.second.first;
            int total = top.second.second;

            pass += 1 ; total += 1;

            double delta = (double)(pass + 1) / (total + 1) - (double)pass / total;
            maxHeap.push({delta, {pass, total}});
        }
        double totalRatio = 0;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int pass = top.second.first;
            int total = top.second.second;
            totalRatio += (double)pass / total;
        }
        return totalRatio / classes.size();
    }
};