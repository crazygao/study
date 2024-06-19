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
    int validate_following(unsigned char sub_byte) {
        if ((sub_byte & mask_first_two_bits) != mask_first_bit) {
            return -1;
        }
        return sub_byte & mask_last_six_bits;
    }
    int validate_xutf(string xutf) {
        int xutf_length = 0;
        int sum = 0;
        istringstream hex_stream(xutf);
        unsigned int xutf_int;
        hex_stream >> hex >> xutf_int;
        stack<unsigned char>* bytes = new stack<unsigned char>();
        // 1. break down the xutf into bytes
        unsigned char first_byte = 0;
        while(xutf_int > 0xFF) {
            unsigned char first_byte = xutf_int & 0xFF;
            bytes->push(first_byte);
            xutf_int = xutf_int >> 8;
            xutf_length++;
        }
        first_byte = xutf_int;

        int num_bytes = 0;
        if ((first_byte & mask_first_bit) == 0) {
            num_bytes = 1;
            if (bytes->size() != 0) {
                return -1;
            }
            sum = first_byte;
            return sum;
        } else if ((first_byte & mask_first_three_bits) == mask_first_two_bits) {
            num_bytes = 2;
            if (bytes->size() != 1) {
                return -1;
            }
            sum = first_byte & mask_last_five_bits;
        } else if ((first_byte & mask_first_four_bits) == mask_first_three_bits) {
            num_bytes = 3;
            if (bytes->size() != 2) {
                return -1;
            }
            sum = first_byte & mask_last_four_bits;
        } else if ((first_byte & mask_first_five_bits) == mask_first_four_bits) {
            num_bytes = 4;
            if (bytes->size() != 3) {
                return -1;
            }
            sum = first_byte & mask_last_three_bits;
        } else if ((first_byte & mask_first_six_bits) == mask_first_five_bits) {
            num_bytes = 5;
            if (bytes->size() != 4) {
                return -1;
            }
            sum = first_byte & mask_last_two_bits;
        } else if ((first_byte & mask_first_seven_bits) == mask_first_six_bits) {
            num_bytes = 6;
            if (bytes->size() != 5) {
                return -1;
            }
            sum = first_byte & mask_last_bit;
        } else {
            return -1;
        }
        while (!bytes->empty()) {
            unsigned char sub_byte = bytes->top();
            bytes->pop();
            int sub_byte_value = validate_following(sub_byte);
            if (sub_byte_value == -1) {
                return -1;
            }
            sum = (sum << 6) + sub_byte_value;
        }
        return sum;
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
