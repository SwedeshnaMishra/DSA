//2657. Find the Prefix Common Array of Two Arrays

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        unordered_set<int> seenA, seenB;
        
        for (int i = 0; i < n; ++i) {
            seenA.insert(A[i]);
            seenB.insert(B[i]);
            
            int commonCount = 0;
            for (int x : seenA) {
                if (seenB.count(x)) {
                    ++commonCount;
                }
            }
            
            C[i] = commonCount;
        }
        
        return C;
    }
};
