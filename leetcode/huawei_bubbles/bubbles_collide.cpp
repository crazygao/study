#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> collide(vector<int> w) {
        stack<int> s;
        for (int i = 0; i < w.size();) {
            if (s.empty()) {
                s.push(w[i]);
                i++;
                continue;
            }
            if (s.top() > 0 && w[i] < 0) {
                // collide
                int collision = s.top() + w[i];
                if (collision == 0) {
                    s.pop();
                    i++;
                } else if (collision < 0) {
                    s.pop();
                } else {
                    // do nothing
                    i++;
                }
                continue;
            }
            s.push(w[i]);
            i++;
        }
        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
template <class T>
ostream& operator<<(ostream& os, vector<T>& nums) {
    for (typename vector<T>::iterator p = nums.begin(); p != nums.end(); ++p) {
        os << *p << ' ';
    }
    return os;
}

int main() {
    Solution* sol = new Solution();
    vector<int> nums1{-4, 3, 1, -2, -3};
    vector<int> abc = sol->collide(nums1);

    cout <<  abc << endl;
}
