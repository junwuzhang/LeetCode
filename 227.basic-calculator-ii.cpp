/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */
class Solution {
public:
    int calculate(string s) {
        int idx = 0;
        long long result = 0, last_number = 0, tmp_result = 0;
        char last_op = '+';
        while (idx < s.size()) {
            if (isdigit(s[idx])){
                last_number = 0;
                // keep reading if isdigit(curr_char) is true
                while (idx < s.size() && isdigit(s[idx])) {
                    last_number = last_number * 10 + s[idx] - '0';
                    idx++;
                }
                if (last_op == '+' || last_op == '-'){
                    result += tmp_result;
                    tmp_result = last_number * 
                        (last_op == '+' ? 1 : -1);
                } else if (last_op == '*'){
                    tmp_result *= last_number;
                } else if (last_op == '/'){
                    tmp_result /= last_number;
                }
                continue;
            }
            else if (s[idx] != ' ') {
                last_op = s[idx];
            }
            idx++;
        }
        result += tmp_result;
        return result;
    }
};

