// 29. Divide Two Integers
// Number -> sign + number,
// calculate sign
// calculate positive divide result.
// add sign.
// 7 / (-2) = (-7) / 2 = -4,
// -128 / -1 = 128 --> overflow, this is the only case, if touch 128 is overflow?
//
#include <iostream>

using namespace std;

class Solution{
    public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return 2^31 - 1;
        }
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            return -dividend;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long _dividend = labs(dividend), _divisor = labs(divisor), answer = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1: 1;
        while (_dividend >= _divisor) {
            long temp = _divisor, multiplier = 1;
            while(temp << 1 <= _dividend) {
                temp <<= 1;
                multiplier <<= 1;
            }
            _dividend -= temp;
            answer += multiplier;
        }
        return sign * answer;
    }
};

int main(int argc, char** argv) {
    int dividend = atoi(argv[1]);
    int divisor = atoi(argv[2]);
    Solution solution;
    cout << solution.divide(dividend, divisor) << endl;
}
