#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int lhelper = 0, rhelper = 0, midhelper = 0;
        int mid = 0, llim = -1, rlim = -1;
        if (right - left == 0) {
            if (nums[right] == target) {
                return vector<int> {0, 0};
            } else {
                return vector<int> {-1, -1};
            }
        }
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
                continue;
            } else if(nums[mid] < target) {
                left = mid + 1;
                continue;
            } else if (nums[mid] == target) {
                lhelper = left;
                rhelper = mid;
                while (lhelper <= rhelper) {
                    if (rhelper - lhelper <= 1) {
                        if (nums[lhelper] < nums[rhelper]) llim = rhelper;
                        else llim = lhelper;
                        break;
                    }
                    midhelper = (lhelper + rhelper) / 2;
                    if (nums[midhelper] < target && nums[midhelper + 1] != target) {
                        lhelper = midhelper + 1;
                        continue;
                    } else if (nums[midhelper] < target && nums[midhelper + 1] == target) {
                        llim = midhelper + 1;
                        break;
                    }
                    else {
                        rhelper = midhelper ;
                    }
                }
                lhelper = mid;
                rhelper = right;
                while (lhelper < rhelper) {
                    if (rhelper - lhelper == 1) {
                        if (nums[lhelper] < nums[rhelper]) rlim = lhelper;
                        else rlim = rhelper;
                        break;
                    }
                    midhelper = (lhelper + rhelper) / 2;
                    if (nums[midhelper] > target && nums[midhelper - 1] != target) {
                        rhelper = midhelper - 1;
                        continue;
                    } else if (nums[midhelper] > target && nums[midhelper - 1] == target) {
                        rlim = midhelper - 1;
                        break;
                    }
                    else {
                        lhelper = midhelper ;
                    }
                }
                break;
            }
        }
        return vector<int> {llim, rlim};
    }
};

int main() {
    vector<int> a{1, 4};
    Solution sol;
    vector<int> a1 = sol.searchRange(a, 4);
    cout << a1[0] << " " << a1[1] << endl;
}
