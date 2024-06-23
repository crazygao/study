Checksum
given a target string str,
1. if len(str) is not a multiple of 4 in bytes, append 0xFF to the end of str until len(str) is a multiple of 4 in bytes.
then, calculate the checksum of str.
2. len(str) / 4 = n
3. if n == 1, the content of str is the checksum.
4. if n > 1, str[0:4] ^ str[4:8] ^ ... ^ str[(n-1)*4:n*4] is the checksum.