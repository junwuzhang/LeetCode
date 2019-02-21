/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (31.23%)
 * Total Accepted:    148.8K
 * Total Submissions: 476.1K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Note:
 * 
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // "outside-in" recursion
        // if size == 1, return as answer
        // search tokens to find a non-integer character
        // extract the two previous integers, perform operations
        // replace the three elements with one element (calculation result)
        // call function again on remaining tokens
        
        // "inside-out recursion: easier", similar idea, but recurse on last operation first
        string ch = tokens.back();    tokens.pop_back();
        if (ch != "+" && ch!="-" && ch!="*" && ch!="/") {
            return atoi(ch.c_str());
        }
        else{
            int num2 = evalRPN(tokens);
            int num1 = evalRPN(tokens);
            if (ch == "+"){
                return num1 + num2;
            }
            if (ch == "-"){
                return num1 - num2;
            }
            if (ch == "*"){
                return num1 * num2;
            }
            if (ch == "/"){
                return num1 / num2;
            }
        }
        return 0;        
    }
};
