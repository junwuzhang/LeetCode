/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (51.29%)
 * Total Accepted:    124.3K
 * Total Submissions: 242.4K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */
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


