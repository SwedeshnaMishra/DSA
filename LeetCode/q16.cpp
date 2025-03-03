//2182. Construct String With Repeat Limit

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        priority_queue<pair<char, int>> maxHeap;
        for(auto &[ch, count] : freq)
    {
    maxHeap.push({ch, count});
    } 
    string result = "";

    while(!maxHeap.empty()) {
        auto[currentChar, currentCount] = maxHeap.top();
        maxHeap.pop();

        int repeatTimes = min(currentCount, repeatLimit);
        result.append(repeatTimes, currentChar);
        currentCount -= repeatTimes;

        if(currentCount > 0) {
            if (maxHeap.empty()) break;

            auto [nextChar, nextCount] = maxHeap.top();
            maxHeap.pop();

            result += nextChar;
            nextCount--;

            if (nextCount > 0) {
                maxHeap.push({nextChar, nextCount});
            }
            maxHeap.push({currentChar, currentCount});
        }
    }
    return result;
   }

};