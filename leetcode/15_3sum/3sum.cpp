#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>* res = new vector<vector<int>>();
        if (nums.size() <= 2) return *res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i ++) {
            if (i == 0 || i > 0 && nums[i] != nums[i - 1]) {
                int low = i + 1;
                int high = nums.size() - 1;
                int sum = 0 - nums[i];
                while (low < high) {
                    if (nums[low] + nums[high] == sum) {
                        vector<int> v{nums[i], nums[low], nums[high]};
                        res->push_back(v);
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        while (low < high && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                    } else if (nums[low] + nums[high] < sum) {
                        low++;
                    } else {
                        high--;
                    }
                }
            }
        }
        return *res;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> a = {};
    vector<vector<int>> aout = sol->threeSum(a);
    for (auto iterator = aout.begin(); iterator != aout.end(); iterator++) {
        for(auto jterator = iterator->begin();jterator != iterator->end(); jterator++) {
            cout << *jterator;
        }
        cout << endl;
    }
}
