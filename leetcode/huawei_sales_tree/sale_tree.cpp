#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>
using namespace std;
class Node {
public:
    string id;
    int count;
    vector<string> children;
    Node(string id, int count) {
        this->id = id;
        this->count = count;
    }
};

class Solution {
public:
    unordered_map<int, int> layered_sales;
    Solution() {
        layered_sales = unordered_map<int, int>();
    }
    void sales_tree(unordered_map<string, Node*>& sales, string target_id, int layer = 1) {
        Node* target = sales.find(target_id) == sales.end() ? nullptr : sales[target_id];
        if (layered_sales.find(layer) == layered_sales.end()) {
            // initialize the layer
            layered_sales[layer] = 0;
        }
        layered_sales[layer] += 1;
        if (target == nullptr) {
            // leaf node
            return;
        }
        for (auto target_child_id : target->children) {
            sales_tree(sales, target_child_id, layer + 1);
        }
    }
    void get_max_sales_layer(int& max_layer, int& max_sales) {
        max_layer = 0;
        max_sales = 0;
        for (auto it = layered_sales.begin(); it != layered_sales.end(); ++it) {
            if (it->second > max_sales) {
                max_sales = it->second;
                max_layer = it->first;
            }
            if (it->second == max_sales && it->first < max_layer) {
                max_layer = it->first;
            }
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
    int n; // n is the number of sales
    cin >> n;
    cin.ignore(256, '\n');
    unordered_map<string, Node*> sales;

    int m; // m is the number of following lines
    cin >> m;
    cin.ignore(256, '\n');

    for (int i = 0; i < m; ++i) {
        string line;
        getline(cin, line, '\n');
        istringstream iss(line);
        string id;
        string sub_count_str;
        string sub_id;

        getline(iss, id, ' ');
        getline(iss, sub_count_str, ' ');
        int sub_count = stoi(sub_count_str);
        sales[id] = new Node(id, sub_count);
        for (int j = 0; j < sub_count; ++j) {
            getline(iss, sub_id, ' ');
            sales[id]->children.push_back(sub_id);
        }
    }

    string target_id;
    cin >> target_id;

    sol->sales_tree(sales, target_id, 1);
    int max_layer;
    int max_sales;
    sol->get_max_sales_layer(max_layer, max_sales);
    cout << max_layer << ' ' << max_sales << endl;
}
