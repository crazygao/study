#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            int len = s.length();
            if (len <= 1) return s;
            bool** state = new bool*[len];
            int i, longestPalindromeLength = 1, longestPalindromeStart = 0;
            for (i = 0; i < len; i++) {
                state[i] = new bool[len];
            }
            for (i = 0; i < len; i++) {
                state[i][i] = true;
            }
            for (i = len - 1; i>=0; i--) {
                for (int dist = 1; dist < len - i; dist++) {
                    int j = dist + i;
                    if (dist == 1) {
                        state[i][j] = s[i] == s[j];
                    }
                    else {
                        state[i][j] = (s[i] == s[j]) && state[i + 1][j - 1];
                    }
                    if (state[i][j] && j - i + 1 > longestPalindromeLength) {
                        longestPalindromeLength = j - i + 1;
                        longestPalindromeStart = i;
                    }
                }
            }
            for (i = 0; i < len; i++) {
                delete[] state[i];
            }
            delete[] state;
            return s.substr(longestPalindromeStart, longestPalindromeLength);
        }
};

int main() {
    string s = "abcdcdcba";
    Solution *sol = new Solution();
    cout << sol->longestPalindrome(s) << endl;
    cout << sol->longestPalindrome("abcbcd") << endl;
}
