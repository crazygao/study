#include <ios>
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
    unsigned int checksum(string input) {
        unsigned int checksum = 0;
        while (input.length() % 4 != 0) {
            input += '\xff';
        }
        bool initialize = true;
        unsigned int sum_of_four = 0;
        int loop_of_four = 0;
        for (char c : input) {
            if (loop_of_four == 4) {
                if (initialize) {
                    checksum = sum_of_four;
                    initialize = false;
                } else {
                    checksum ^= sum_of_four;
                }
                sum_of_four = 0;
                loop_of_four = 0;
            }
            if (loop_of_four == 0) {
                sum_of_four = unsigned(c);
            } else {
                sum_of_four = (sum_of_four << 8) + unsigned(c);
            }
            loop_of_four++;
        }
        if (initialize) {
            checksum = sum_of_four;
            initialize = false;
        } else {
            checksum ^= sum_of_four;
        }
        return checksum;
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
    string original_string;
    cin >> original_string;
    cout << std::showbase << hex << sol->checksum(original_string) << endl;
}
