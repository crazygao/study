// 1. __buildin_popcount is similar functionality, use special CPU instructions.

// 2. This is series counting.
// split it by 2^0 = 1, 2^1 = 2, 2^2 = 4, 2^3 = 8
// cB(0) = [0] 0 not counting
// cB(1) = [0, 1]
// cB(2) = [cB(1), 1]
// cb(3) = [cb(2), 1 + cb(1)]
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int>* values = new vector<int>(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                (*values)[i] = (*values)[i >> 1] + i%2;
            }
            return *values;
        }
};
