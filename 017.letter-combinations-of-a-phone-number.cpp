/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (40.19%)
 * Total Accepted:    342.5K
 * Total Submissions: 851.9K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    // use recursion backtracking (DFS)

    // initialize some global variables
    map<int, vector<char> > m;
    string singleString;
    vector<string> output;
    int size;

    vector<string> letterCombinations(string digits) {
        size = digits.size();
        if (size == 0) return {};
        initialize();
        backtrack(digits);
        return output;
    }
private:

    void backtrack(string digits) {
        // convert the first character of the string to an integer digit
        int currDigit = digits[0] - '0';
        // if this key exists in the number-character mapping
        if (m.count(currDigit)) {
            // set the current character
            for (int i=0; i<m[currDigit].size(); i++){
                char currChar = m[currDigit][i];
                singleString += currChar;
                backtrack(digits.substr(1, digits.size()));     // DFS
                singleString.erase(singleString.end() - 1);     // backtrack
            }
        }
        if (singleString.size() == size) output.push_back(singleString);
    }
    void initialize(){
        m[2] = {'a', 'b', 'c'};
        m[3] = {'d', 'e', 'f'};
        m[4] = {'g', 'h', 'i'};
        m[5] = {'j', 'k', 'l'};
        m[6] = {'m', 'n', 'o'};
        m[7] = {'p', 'q', 'r', 's'};
        m[8] = {'t', 'u', 'v'};
        m[9] = {'w', 'x', 'y', 'z'};
    }
};
