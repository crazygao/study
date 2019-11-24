#include <vector>
#include <pair>
using namespace std;
class Solution {
    pair<int, int> find_if(vector<int>& nums1, vector<int>& nums2, size_t imin, size_t imax, size_t m, size_t n) {
	size_t i = (imin + imax) / 2;
	size_t j = (m + n + 1) / 2 - i;
	// pause
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	size_t m = nums1.size();
	size_t n = nums2.size();
        // 1. imin = 0, imax = m, find_i [imin, imax]
	// 2. i = (imin + imax)/2, j = (m + n + 1)/2 - i
	// 3.a nums2[j - 1] <= nums1[i] and nums1[i - 1] <= nums2[j], ====Success
	// 3.b nums2[j - 1] > A[i]: i is small. increase i, imin = i + 1, imax = 2, find_i
	// 3.c nums1[i - 1] > nums2[j], decrease i, imax = i - 1, find_i
    }
};
