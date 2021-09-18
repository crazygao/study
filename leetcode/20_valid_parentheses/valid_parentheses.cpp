#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            stack<char> charstack{};
            bool succeeded = true;
            for (auto& schar : s) {
                if (schar == '{' or schar == '[' or schar == '(') {
                    charstack.push(schar);
                }
                if (schar == '}') {
                    if (charstack.empty()) {
                        succeeded = false;
                        break;
                    }
                    if (charstack.top() == '{') {
                        charstack.pop();
                        continue;
                    } else {
                        succeeded = false;
                        break;
                    }
                }
                if (schar == ']') {
                    if (charstack.empty()) {
                        succeeded = false;
                        break;
                    }
                    if (charstack.top() == '[') {
                        charstack.pop();
                        continue;
                    } else {
                        succeeded = false;
                        break;
                    }
                }
                if (schar == ')') {
                    if (charstack.empty()) {
                        succeeded = false;
                        break;
                    }
                    if (charstack.top() == '(') {
                        charstack.pop();
                        continue;
                    } else {
                        succeeded = false;
                        break;
                    }
                }
            }
            return succeeded && charstack.empty();
        }
};

int main() {
    string s = "[][[(({}))]]";
    string s1 = "[[[]";
    string s2 = "";
    Solution* sol = new Solution();
    cout << sol->isValid(s) << sol->isValid(s1) << sol->isValid(s2) << endl;
}
