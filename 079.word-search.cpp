/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (30.26%)
 * Total Accepted:    248.5K
 * Total Submissions: 821.2K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:       
    bool backtrack(vector<vector<char>>& board, string word, vector<vector<int> > &usage, int i, int j, int idx){
        // if current element is the character need to be found (base case)
        if (board[i][j] == word[idx] && usage[i][j] == 0){
            // check cell as used, check character as found and move on to the next character
            usage[i][j] = 1;
            if (idx+1 == word.size()) return true;
            idx++;
            // recursion cases: check if adjacent cells contain the character
            if ((i+1<board.size()    && backtrack(board, word, usage, i+1, j, idx)) ||
                (i-1>=0               && backtrack(board, word, usage, i-1, j, idx)) ||
                (j+1<board[i].size() && backtrack(board, word, usage, i, j+1, idx)) ||
                (j-1>=0               && backtrack(board, word, usage, i, j-1, idx)) ){
                return true;
            }
            usage[i][j] = 0;        
        }        
        return false;        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // for i in rows and j in cols:
        // check if the element is the first letter of the word
        // if yes:
        // pass the element around it and letter minus the first character to the recursion function
        
        if (board.size()<=0 || word.size()<=0) return false;
        // create a new grid to indicate usage of each cell
        vector< vector<int> > mask(board.size(), vector<int>(board[0].size(), 0));
        
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] == word[0]){
                    // call recursive function
                    vector< vector<int> > usage = mask;
                    if (backtrack(board, word, usage, i, j, 0)) return true;
                }
            }
        }
        return false;
    }

};
