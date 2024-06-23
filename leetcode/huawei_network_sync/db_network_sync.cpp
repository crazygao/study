#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

class Node {
public:
    int neId;
    string neName;
    int neFlag;
};

bool operator<(const Node& a, const Node& b) {
    return a.neId < b.neId;
}

class Solution {
public:
    unordered_map<int, Node*> curTable;
    unordered_map<int, Node*> bakTable;
    Solution() {
        curTable = unordered_map<int, Node*>();
        bakTable = unordered_map<int, Node*>();
    }
    void insertCurTableLine(string line) {
        istringstream iss(line);
        string neId, neName, neFlag;
        getline(iss, neId, ' ');
        getline(iss, neName, ' ');
        getline(iss, neFlag, ' ');
        Node* node = new Node();
        node->neId = stoi(neId);
        node->neName = neName;
        node->neFlag = stoi(neFlag);
        curTable[node->neId] = node;
    }
    void insertBakTableLine(string line) {
        istringstream iss(line);
        string neId, neName;
        getline(iss, neId, ' ');
        getline(iss, neName, ' ');
        Node* node = new Node();
        node->neId = stoi(neId);
        node->neName = neName;
        node->neFlag = 0;
        bakTable[node->neId] = node;
    }

    void sync() {
        for (auto it = bakTable.begin(); it != bakTable.end(); ++it) {
            if (curTable.find(it->first) == curTable.end()) {
                curTable[it->first] = it->second;
            } else {
                if (curTable[it->first]->neName != it->second->neName) {
                    curTable[it->first]->neName = it->second->neName;
                }
            }
        }
    }
    void sortAndOutputCurTable() {
        vector<Node> nodes;
        for (auto it = curTable.begin(); it != curTable.end(); ++it) {
            nodes.push_back(*(it->second));
        }
        sort(nodes.begin(), nodes.end());
        for (int i = 0; i < nodes.size(); ++i) {
            cout << nodes[i].neId << ' ' << nodes[i].neName << ' ' << nodes[i].neFlag << endl;
        }
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
        sol->insertCurTableLine(line);
    }

    int m;
    cin >> m;
    cin.ignore(256, '\n');
    for (int i = 0; i < m; ++i) {
        string line;
        getline(cin, line);
        sol->insertBakTableLine(line);
    }

    sol->sync();

    sol->sortAndOutputCurTable();
}
