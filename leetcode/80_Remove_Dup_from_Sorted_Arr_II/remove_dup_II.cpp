#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int i = 0;
        for (int j = 0; j < n; j++) {
            // 1st and 2nd elements are always kept
            // if the j element is different from the 1st element, keep it
            //
            if (i < 2 || nums[j] != nums[i-2]) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

int main()
{
    vector<int> v1 {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution sol;
    cout << sol.removeDuplicates(v1) << endl;
    for (int i: v1) {
        cout << i << " ";
    }
}
