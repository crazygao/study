#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
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
int main() {
    Solution sol;
    vector<vector<int>> mat {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5}
    };
    sol.rotate(mat);
    cout << mat << endl;
}
