#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = 0, current_sum = 0;
        int best_start = 0, best_end = 0;
        int idx = 0;
        int current_start = 0, current_end = 0;
        for (idx = 0; idx < nums.size(); ++idx) {
            int x = *(nums.begin() + idx);
            if (current_sum <= 0) {
                current_start = current_end;
                current_sum = x;
            } else {
                current_sum += x;
            }
            
            if (current_sum > best_sum) {
                best_sum = current_sum;
                best_start = current_start;
                best_end = current_end + 1;
            }
        }
        return best_sum;
    }
};

int main() {
    vector<int> avail{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution *sol = new Solution();
    cout << sol->maxSubArray(avail) << endl;
}
