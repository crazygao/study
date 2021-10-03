#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> list;
        vector<vector<int>> heatmap;
        for (auto str: strs) {
            // createHeatmap
            int strheatmap[26] = {0};
            for (auto ch: str) {
                strheatmap[ch - 'a'] ++;
            }
            // compare heatmap
            int index = -1;
            int matchIndex = -1;
            for (int hmIndex = 0; hmIndex < heatmap.size(); hmIndex++) {
                bool match = true;
                for (int i = 0; i < 26; i++) {
                    if (strheatmap[i] != heatmap[hmIndex][i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    matchIndex = hmIndex;
                    break;
                }
            }

            if (matchIndex != -1) {
                list[matchIndex].push_back(str);
            } else {
                list.push_back(vector<string>{str});
                heatmap.push_back(vector<int>(strheatmap, strheatmap + 26));
            }
        }
        return list;
    }
};

template <typename T>
ostream& operator<<(ostream& os, vector<vector<T>>& list) {
    for (auto i : list) {
        for (auto j: i) {
            os << j << ' ';
        }
        os << endl;
    }
    return os;
}

int main() {
    Solution sol;
    vector<string> strs{};
    auto vecstrs = sol.groupAnagrams(strs);
    cout << vecstrs << endl;
}
