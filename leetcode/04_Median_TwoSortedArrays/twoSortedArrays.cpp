#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
    pair<size_t, size_t> find_if(vector<int>& nums1, vector<int>& nums2, size_t imin, size_t imax, size_t m, size_t n) {
        // 2. i = (imin + imax)/2, j = (m + n + 1)/2 - i
        // 3.a nums2[j - 1] <= nums1[i] and nums1[i - 1] <= nums2[j], ====Success
        // 3.b nums2[j - 1] > A[i]: i is small. increase i, imin = i + 1, imax = 2, find_i
        // 3.c nums1[i - 1] > nums2[j], decrease i, imax = i - 1, find_i
        size_t i = (imin + imax) / 2;
        size_t j = (m + n + 1) / 2 - i;
        if (nums2[j - 1] <= nums1[i] && nums1[i - 1] <= nums2[j]) {
            return make_pair(i, j);
        }

        if (nums2[j - 1] > nums1[i]) {
            return find_if(nums1, nums2, i + 1, imax, m, n);
        } else if (nums1[i - 1] > nums2[j]) {
            return find_if(nums1, nums2, imin, i - 1, m, n);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size();
        size_t n = nums2.size();
        // 1. imin = 0, imax = m, find_i [imin, imax]
        pair<size_t, size_t> median_pair = find_if(nums1, nums2, 0, m - 1, m, n);

        size_t i = median_pair.first;
        size_t j = median_pair.second;
        if ((m + n) % 2 == 0) {
            return ( min(nums1[i], nums2[j]) + max(nums1[i - 1], nums2[j - 1]) ) / 2;
        } else {
            return max(nums1[i - 1], nums2[j - 1]);
        }
    }
};

int main() {
    int ints1[] = {1, 3, 5, 7};
    int ints2[] = {2};
    vector<int> A (ints1, ints1 + 4);
    vector<int> B (ints2, ints2 + 2);
    Solution solution;
    cout << solution.findMedianSortedArrays(A, B) << endl;
}
