/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.45%)
 * Total Accepted:    473.3K
 * Total Submissions: 1.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int i = 0, left = 0, right = 0;
        int startIdx = 0, maxLen = 0; 
        while(i < s.size()){
            left = i;
            right = i;
            // find the center for even number case
            while (right < s.size()-1 && s[right] == s[right+1]) right++;
            // increment i by 1
            i = right + 1;
            // expand to the sides 
            // (if the one further left and the one further right equal each other)
            while (left > 0 && right < s.size()-1 && s[left - 1] == s[right + 1]){
                right++;
                left--;
            }
            int currLen = right - left + 1;
            if(currLen > maxLen) {
                startIdx = left;
                maxLen = currLen;
            }
        }
        return s.substr(startIdx, maxLen);
    }
};
