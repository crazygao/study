#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
using namespace std;

class Node {
public:
    int id;
    int capacity;;
    vector<Node*> children;
    Node(int id, int capacity) {
        this->id = id;
        this->capacity = capacity;
    }
};

class Solution {
public:

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
    int n;
    cin >> n;
    cin.ignore(256, '\n');
    vector<string> paths;
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        paths.push_back(line);
    }
    string res = sol->cd(paths);
    cout << res << endl;
}
