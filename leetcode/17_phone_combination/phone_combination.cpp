#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return vector<string>{};
        }
        vector<string> mapping{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> results{""};
        for (auto dig:digits) {
            vector<string> temp;
            for (auto chr:mapping[dig - '0']) {
                for (auto str: results) {
                    temp.push_back(str + chr);
                }
            }
            results.swap(temp);
        }
        return results;
    }
};

int main()
{
    Solution sol;
    auto comb = sol.letterCombinations("23");
    for (auto combi : comb) {
        cout << combi << endl;
    }
}
