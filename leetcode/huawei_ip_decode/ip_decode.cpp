#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

unsigned char mask_all_bit = 0b11111111;
unsigned char mask_first_seven_bits = 0b11111110;
unsigned char mask_first_six_bits = 0b11111100;
unsigned char mask_first_five_bits = 0b11111000;
unsigned char mask_first_four_bits = 0b11110000;
unsigned char mask_first_three_bits = 0b11100000;
unsigned char mask_first_two_bits = 0b11000000;
unsigned char mask_first_bit = 0b10000000;
unsigned char mask_last_bit = 0b00000001;
unsigned char mask_last_two_bits = 0b00000011;
unsigned char mask_last_three_bits = 0b00000111;
unsigned char mask_last_four_bits = 0b00001111;
unsigned char mask_last_five_bits = 0b00011111;
unsigned char mask_last_six_bits = 0b00111111;

class Solution {
public:
    int validate_xutf(string xutf) {

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
    string xutf_string;
    cin >> xutf_string;
    cout << sol->validate_xutf(xutf_string) << endl;
}
