#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    private:
        void backtrack(vector<vector<int>>& list, vector<int>& curNums, const vector<int>& nums) {
            if (curNums.size() == nums.size()) {
                list.push_back(curNums);
            }
            else {
                for (int i = 0; i < nums.size(); i++) {
                    auto found = find(curNums.begin(), curNums.end(), nums[i]);
                    if (found != curNums.end()) continue;
                    curNums.push_back(nums[i]);
                    backtrack(list, curNums, nums);
                    curNums.pop_back();
                }
            }

        }
    public:
        vector<vector<int>> permute(vector<int> &nums) {
            vector<vector<int>> list;
            vector<int> curNums;
            backtrack(list, curNums, nums);
            return list;
        }
};

ostream& operator<<(ostream& os, vector<vector<int>>& list) {
    for (auto i : list) {
        for (auto j: i) {
            os << j << ' ';
        }
        os << endl;
    }
    return os;
}

int main()
{
    vector<int> cand1 {2,3,5};
    Solution sol;
    vector<vector<int>> v1 = sol.permute(cand1);
    cout << v1 << endl;
}
