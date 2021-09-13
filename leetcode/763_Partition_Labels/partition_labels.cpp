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
        void initPartitions(string s) {
            for (auto it = s.cbegin(); it != s.cend(); it++) {
                int distance = it - s.cbegin();

            }
        }
        vector<int> partitionLabels(string s) {
            
        }
};
