#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            // if begin < end, normal bi-search
            int sizenums = nums.size();
            if (nums[0] < nums[sizenums - 1]) {
                return searchNormal(nums, target, 0, sizenums - 1);
            } else {
                return searchAbnormal(nums, target, 0, sizenums - 1);
            }
        }
        int searchNormal(vector<int>& nums, int target, int begin, int end) {
            int numsB = nums[begin];
            int numsE = nums[end];
            if (target < numsB || target > numsE) {
                return -1;
            }
            if (end - begin <= 1) {
                if (target == numsB) return begin;
                if (target == numsE) return end;
                return -1;
            }
            int n = (begin + end) / 2;
            int numsN = nums[n];
            if (numsN == target) return n;
            if (numsB < numsN && target < numsN && target >= numsB) {
                return searchNormal(nums, target, begin, n - 1);
            }
            if (numsN < numsE && target <= numsE && target > numsN) {
                return searchNormal(nums, target, n + 1, end);
            }
            return -1;
        }
        int searchAbnormal(vector<int>& nums, int target, int begin, int end) {
            int numsB = nums[begin];
            int numsE = nums[end];
            if (target < numsB && target > numsE) {
                return -1;
            }
            if (end - begin <= 1) {
                if (target == numsB) return begin;
                if (target == numsE) return end;
                return -1;
            }
            int n = (begin + end) / 2;
            int numsN = nums[n];
            if (numsN == target) return n;
            if (numsB < numsN && target < numsN && target >= numsB) {
                return searchNormal(nums, target, begin, n - 1);
            }
            if (numsB >= numsN && (target >= numsB || target < numsN)) {
                return searchAbnormal(nums, target, begin, n - 1);
            }
            if (numsN < numsE && target <= numsE && target > numsN) {
                return searchNormal(nums, target, n + 1, end);
            }
            if (numsN >= numsE && (target > numsN || target <= numsE)) {
                return searchAbnormal(nums, target, n + 1, end);
            }
            return -1;
        }
};

int main() {
    Solution sol;
    vector<int> vec{1, 3, 5};
    cout << sol.search(vec, 3) << endl;
}
