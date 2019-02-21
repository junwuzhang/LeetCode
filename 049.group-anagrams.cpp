/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (44.48%)
 * Total Accepted:    292.8K
 * Total Submissions: 657.9K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
class Solution {
public:
    // tell anagrams from occurances of each character
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        map<string, vector<string>> m;
        // loop through all words
        for (int i=0; i<strs.size(); i++){
            string wordLetters = strs[i];
            sort(wordLetters.begin(), wordLetters.end());
            m[wordLetters].push_back(strs[i]);
        }
        // convert map to vector
        for( auto it = m.begin(); it != m.end(); ++it ) {
            output.push_back( it->second );
        }
        return output;
    }
};
