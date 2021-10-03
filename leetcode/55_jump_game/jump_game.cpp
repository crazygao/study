#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0, size = nums.size() - 1;
        int lastmax = -1;
        int depth = 0;
        bool canJump = true;
        while(max < size) {
            if (lastmax == max) {
                canJump = false;
                break;
            }
            int temp = max;
            for (int i = lastmax + 1; i <= temp; i++) {
                max = max > i + nums[i] ? max : i + nums[i];
            }
            lastmax = temp;
        }
        return canJump;
    }
};

int main()
{
    vector<int> v1 {2, 3, 1, 1, 4};
    Solution sol;
    cout << sol.canJump(v1) << endl;

    vector<int> v2 {3, 2, 1, 0, 4};
    cout << sol.canJump(v2) << endl;
}
