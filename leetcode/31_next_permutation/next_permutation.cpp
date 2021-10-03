#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        int l = -1;
        int numK = 0;
        if (nums.size() < 2) {
            return;
        }
        for (auto iter = nums.begin() + 1; iter != nums.end(); iter++) {
            if (*iter > *(iter - 1)) {
                k = iter - nums.begin() - 1;
                numK = *(iter - 1);
            }
            if (k != -1 && *iter > numK) {
                l = iter - nums.begin();
            }
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end());
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};

template <class T>
ostream& operator<<(ostream& os, vector<T>& nums) {
    for (typename vector<T>::iterator p = nums.begin(); p != nums.end(); ++p) {
        os << *p << ' ';
    }
    return os;
}
int main()
{
    Solution sol;
    vector<int> nums{1, 1};
    sol.nextPermutation(nums);
    cout << nums << endl;
    sol.nextPermutation(nums);
    cout << nums << endl;
    sol.nextPermutation(nums);
    cout << nums << endl;
    sol.nextPermutation(nums);
    cout << nums << endl;
    sol.nextPermutation(nums);
    cout << nums << endl;
    sol.nextPermutation(nums);
    cout << nums << endl;
}
