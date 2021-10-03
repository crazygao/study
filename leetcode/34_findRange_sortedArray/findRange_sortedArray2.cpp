#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid = 0;
        vector<int> result {-1, -1};
        if (n == 0) {
            return result;
        }
        while (left < right) {
            mid = (left + right ) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[i] != target) {
            return result;
        } else {
            result[0] = left;
        }
        
        right = n - 1;
        while (left < right) {
            mid = (left + right) / 2 + 1;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        result[1] = right;

        return result;
    }
};

int main() {
    vector<int> a{1, 4};
    Solution sol;
    vector<int> a1 = sol.searchRange(a, 4);
    cout << a1[0] << " " << a1[1] << endl;
}
