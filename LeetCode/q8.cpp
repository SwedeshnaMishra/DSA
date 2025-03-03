//2337. Move Pieces to Obtain a String

class Solution {
public:
    bool canChange(string start, string target) {
        string sFiltered, tFiltered;
        for (char c : start) {
            if (c != '_') sFiltered += c;
        }
        for (char c : target) {
            if (c != '_') tFiltered += c;
        }
        if (sFiltered != tFiltered) return false;

        int sIndex = 0, tIndex = 0, n = start.size();
        while (sIndex < n && tIndex < n) {
            while (sIndex < n && start[sIndex] == '_') sIndex++;
            while (tIndex < n && target[tIndex] == '_') tIndex++;

            if (sIndex < n && tIndex < n) {
                if (start[sIndex] != target[tIndex]) return false;

                if (start[sIndex] == 'L' && sIndex < tIndex) return false;

                if (start[sIndex] == 'R' && sIndex > tIndex) return false;

                sIndex++;
                tIndex++;
            }
        }
        return true;
    }
    
};