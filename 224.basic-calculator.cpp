/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        int curr_sign = 1;
        long long number = 0, result = 0;
        signs.push(curr_sign);  // always positive at left

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                number = number * 10 + c - '0';
            }
            if (c == '+' || c == '-') {
                // calculate current results so far before the plus or minus sign
                result = result + signs.top() * curr_sign * number;
                number = 0;
                curr_sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                // take the previous sign and store in stack
                signs.push(curr_sign * signs.top());
                curr_sign = 1;
            } else if (c == ')') {
                // calculate results so far just like +/- signs, but reset sign to 1
                result = result + signs.top() * curr_sign * number;
                number = 0;
                signs.pop();
                curr_sign = 1;
            }
        }

        if (number != 0) {
            result = result + signs.top() * curr_sign * number;
        }

        return result;
    }
};
// @lc code=end

