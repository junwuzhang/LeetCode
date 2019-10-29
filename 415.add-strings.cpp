/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        char curr_digit = '0';
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while(i >= 0 || j >= 0 || carry) {
            long sum = 0;
            // if statements are needed when when carry != 0
            // but i and j are less than 0
            if(i >= 0) {
                sum += (num1[i] - '0');
                i--;
            }
            if(j >= 0) {
                sum += (num2[j] - '0');
                j--;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            curr_digit = '0' + sum;
            result = curr_digit + result;
        }
        return result;
    }
};
// @lc code=end

