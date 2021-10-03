#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max = 0;
        int lastmax = -1;
        int depth = 0;
        int end = nums.size() - 1;
        while (max < end) {
            int temp = max;
            for (int i = lastmax + 1; i <= temp; i++) {
                max = i + nums[i] > max ? i + nums[i] : max;
            }
            lastmax = temp;
            depth++;
        }
        return depth;
    }
};

int main() {
    Solution sol;
    vector<int> nums{2, 3, 1, 1, 4};
    cout << sol.jump(nums) << endl;
}
