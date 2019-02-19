class Solution {
public:
    int getSum(int a, int b) {
    long long carry; // 64-bit
    while (b) {
        carry = a & b;
        a = a ^ b;
        b = ((carry & 0xffffffff) << 1); // limited to 32 bits
    }
    return a;
    }
};

/* Great solution!!
 * For those not understanding this:
 * Given 14 and 13 (1110 and 1101 respectively)
 * first sum = 00011 (3) as: 1110 ^ 1101 = 0011
 * next b = 1100 << 1 == 11000 (24) as 1110 & 1101 = 1100
 * notice that 3 + 24 is still the sum we want
 * next loop:
 * sum = 11011 (27)
 * b = 000000 << 1 == 0 (as 11000 and 00011 have no overlap) */

