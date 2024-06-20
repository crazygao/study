#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>* buffer = new vector<int>(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            (*buffer)[(i+k) % nums.size()] = nums[i];
        }
        // move buffer back
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (*buffer)[i];
        }
    }
};

// Three time reverse
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> v1 {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution sol;
    sol.rotate(v1, 3);
    for (int i: v1) {
        cout << i << " ";
    }
}
