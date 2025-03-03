//2762. Continuous Subarrays

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long totalSubarrays = 0;
        
        deque<int> minDeque, maxDeque; 
        int start = 0;

        for (int end = 0; end < n; end++) {
            while (!minDeque.empty() && nums[minDeque.back()] > nums[end]) {
                minDeque.pop_back();
            }
            minDeque.push_back(end);

            while (!maxDeque.empty() && nums[maxDeque.back()] < nums[end]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(end);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (minDeque.front() == start) minDeque.pop_front();
                if (maxDeque.front() == start) maxDeque.pop_front();
                start++;
            }

            totalSubarrays += (end - start + 1);
            }
            return totalSubarrays;

    }
};