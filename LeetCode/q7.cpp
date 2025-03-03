//1760. Minimum Limit of Balls in a Bag

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int result = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if (canDivide(nums, maxOperations, mid)) {
                result = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }

        return result;
    }

private:
    bool canDivide(vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > penalty) {
                operations += (balls - 1) / penalty; 
                if (operations > maxOperations) {
                    return false; 
                }
            }
        }
        return true; 
    }
};
