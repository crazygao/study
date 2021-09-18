#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        void moveZeros(vector<int>& nums) {
            vector<int>::iterator p1 = nums.begin();
            vector<int>::iterator p2 = nums.begin();
            for(;p1 != nums.end(); ++p1) {
                if (*p1 == 0) {
                    continue;
                } else {
                    *p2 = *p1;
                    ++p2;
                }
            }
            while(p2 != nums.end()) {
                *p2 = 0;
                ++p2;
            }
        }
};
template <class T>
ostream& operator<<(ostream& os, vector<T>& nums) {
    for (typename vector<T>::iterator p = nums.begin(); p != nums.end(); ++p) {
        os << *p << ' ';
    }
    return os;
}

int main() {
    Solution* sol = new Solution();
    vector<int> nums1{};
    vector<int> nums2{1, 2, 0, 3};
    vector<int> nums3{0, -1, 1, 0, 0, 3};
    sol->moveZeros(nums1);
    sol->moveZeros(nums2);
    sol->moveZeros(nums3);

    cout <<  nums1 << endl;
    cout <<  nums2 << endl;
    cout <<  nums3 << endl;
}
