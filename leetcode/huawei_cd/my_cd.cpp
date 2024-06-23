#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    void push_vector(vector<string>* cur_path, vector<string>* last_path, string step) {
        if (step == "..") {
            cur_path->pop_back();
        } else if (step == ".") {
            // do nothing
        } else {
            cur_path->push_back(step);
        }
    }
    string cd(vector<string> paths) {
        vector<string>* cur_path = new vector<string>();
        cur_path->push_back("/");
        vector<string>* last_path = new vector<string>();
        last_path->push_back("/");
        for (string path : paths) {
            istringstream ss(path);
            string command;
            string path_to_define;
            // delete the first 'cd '
            getline(ss, command, ' ');
            ss >> ws;
            getline(ss, path_to_define);

            // edge case: cd
            if (path_to_define == "") {
                cout << command << endl;
                cout << path_to_define << endl;
                last_path = cur_path;
                cur_path = new vector<string>();
                cur_path->push_back("/");
                continue;
            }

            // -
            if (path_to_define == "-") {
                vector<string>* temp_path = cur_path;
                cur_path = last_path;
                last_path = temp_path;
                continue;
            }
            istringstream sspath(path_to_define);
            string step;

            // absolute path
            if (sspath.peek() == '/') {
                last_path = cur_path;
                cur_path = new vector<string>();
                cur_path->push_back("/");
                sspath.ignore(1);
                while (getline(sspath, step , '/')) {
                    if (step == "") {
                        continue;
                    }
                    push_vector(cur_path, last_path, step);
                }
                continue;
            } else {
                // relative path
                last_path = cur_path;
                cur_path = new vector<string>(*cur_path);
                while (getline(sspath, step , '/')) {
                    if (step == "") {
                        continue;
                    }
                    push_vector(cur_path, last_path, step);
                }
            }
        }
        if (cur_path->at(0) == "/") {
            cur_path->erase(cur_path->begin());
        }
        if (cur_path->size() == 0) {
            return "/";
        }
        auto intermidiate = accumulate(next(cur_path->begin()), cur_path->end(), *cur_path->begin(), [](string a, string b) { return a + '/' + b; });
        return '/' + intermidiate;
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
