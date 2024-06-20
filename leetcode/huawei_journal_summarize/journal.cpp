#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> MAU_DAU;
    unordered_set<string> MAU_HASH;
    map<string, unordered_set<string> > DAU_HASH;
    Solution() {
        MAU_DAU = vector<int>(32, 0);
        MAU_HASH = unordered_set<string>();
        DAU_HASH = {{
            {"01", unordered_set<string>()},
            {"02", unordered_set<string>()},
            {"03", unordered_set<string>()},
            {"04", unordered_set<string>()},
            {"05", unordered_set<string>()},
            {"06", unordered_set<string>()},
            {"07", unordered_set<string>()},
            {"08", unordered_set<string>()},
            {"09", unordered_set<string>()},
            {"10", unordered_set<string>()},
            {"11", unordered_set<string>()},
            {"12", unordered_set<string>()},
            {"13", unordered_set<string>()},
            {"14", unordered_set<string>()},
            {"15", unordered_set<string>()},
            {"16", unordered_set<string>()},
            {"17", unordered_set<string>()},
            {"18", unordered_set<string>()},
            {"19", unordered_set<string>()},
            {"20", unordered_set<string>()},
            {"21", unordered_set<string>()},
            {"22", unordered_set<string>()},
            {"23", unordered_set<string>()},
            {"24", unordered_set<string>()},
            {"25", unordered_set<string>()},
            {"26", unordered_set<string>()},
            {"27", unordered_set<string>()},
            {"28", unordered_set<string>()},
            {"29", unordered_set<string>()},
            {"30", unordered_set<string>()},
            {"31", unordered_set<string>()},
        }};
    }
    void journal(string line) {
        istringstream ss(line);
        string date, ip, url, result;
        getline(ss, date, '|');
        getline(ss, ip, '|');
        getline(ss, url, '|');
        getline(ss, result, '|');
        if (url.find("/login.do") != std::string::npos and result.compare("success") == 0) {
            if (MAU_HASH.find(ip) == MAU_HASH.end()) {
                MAU_HASH.insert(ip);
                MAU_DAU[0] += 1;
            }
            string day = date.substr(8, 2);
            if (DAU_HASH[day].find(ip) == DAU_HASH[day].end()) {
                DAU_HASH[day].insert(ip);
                MAU_DAU[stoi(day)] += 1;
            }
        }
    }
    vector<int> getMAU_DAU() {
        return MAU_DAU;
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
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        sol->journal(line);
    }
    vector<int> res = sol->getMAU_DAU();
    cout << res << endl;
}
