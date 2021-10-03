#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result{};
        if (n == 0) return result;
        string str = "";
        iterateString(result, str, 0, 0, n);
        return result;
    }
    void iterateString(vector<string> &strArr, string str, int left, int right, int n) {
        if (right == n && left == n) { // finish because right is the last one.
            strArr.push_back(str);
            return;
        }
        string temp = str;
        if (left < n) {
            temp = str + "(";
            iterateString(strArr, temp, left + 1, right, n);
        }
        if (right < left) {
            temp = str + ")";
            iterateString(strArr, temp, left, right + 1, n);
        }
        return;
    }
};

int main() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);
    for (auto ires: res) {
        cout << ires << endl;
    }
}
