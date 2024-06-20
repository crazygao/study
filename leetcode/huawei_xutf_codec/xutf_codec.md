X-UTF codec: HUA, 21326.
For single byte, n = 1, first bit is 0, so the code is 0b0xxxxxxx, 0x00-0x7F, 0-127.
For multiple bytes, n > 1, first n bits of the first byte are 1, and the (n+1)th bit is 0, so the code is 0b1110xxxx, the following bytes are 0b10xxxxxx, 0xE0-0xEF, 224-239.
n <= 6, the first byte is 0x1111110x

Provide a function to check if a given string in hexadecimal format is a valid X-UTF code.

Input:
A string in hexadecimal format.
Output:
If the input string is a valid X-UTF code, return decimal number of the code, otherwise return -1.