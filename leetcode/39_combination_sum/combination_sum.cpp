#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
private:
    void backtrack(vector<vector<int>>& list, vector<int>& templist, const vector<int>& candidates, int remain, int start) {
        if (remain < 0) {
            return;
        }
        else if (remain == 0) {
            list.push_back(templist);
        }
        else {
            for (int i = start; i < candidates.size(); i++) {
                templist.push_back(candidates[i]);
                backtrack(list, templist, candidates, remain - candidates[i], i);
                templist.pop_back();
            }
        }
    }
public:
    // general solution for backtrack
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> list;
        vector<int> templist;
        sort(candidates.begin(), candidates.end());
        backtrack(list, templist, candidates, target, 0);
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
    vector<vector<int>> v1 = sol.combinationSum(cand1, 8);
    cout << v1 << endl;
}
