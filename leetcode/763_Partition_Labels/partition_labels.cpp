#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution{
    public:
        // 2. letter to vector<index>
        // 3. leftoverLetterIndexs
        unordered_map<char, vector<int>> partitions;
        typedef unsigned index;
        // template <class T>, T should contain iterator.
        // void initPartitions(T s)
        void initPartitions(string s) {
            for (auto it = s.cbegin(); it != s.cend(); it++) {
                index distance = it - s.cbegin();
                if (partitions.find(*it)) {}

            }
        }
        vector<int> partitionLabels(string s) {
            
        }
};
