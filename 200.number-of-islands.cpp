/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (40.11%)
 * Total Accepted:    297.5K
 * Total Submissions: 741.7K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
class Solution {
public:
    int rowSize, colSize;
    int numIslands(vector<vector<char>>& grid) {
        rowSize = grid.size();
        if(!rowSize) return 0;
        colSize = grid[0].size();
        int counter = 0;
        for (int i=0; i<rowSize; i++){
            for (int j=0; j<colSize; j++){
                if (grid[i][j] == '1'){
                    // run DFS
                    counter++;
                    DFS(grid, i, j);
                }
            }
        }
        return counter;
    }

    void DFS(vector<vector<char>>& grid, int i, int j){
        // // if visited or not part of the island, return
        // if(grid[i][j] == '0') return;
        // mark the cell as visited by crossing it off as part of an island
        grid[i][j] = '0';
        if (i+1 < grid.size() && (grid[i+1][j] == '1')){
            DFS(grid, i+1, j);
        }
        if (i-1 >= 0 && (grid[i-1][j] == '1')) {
            DFS(grid, i-1, j);
        }
        if (j+1 < grid[i].size() && (grid[i][j+1] == '1')){
            DFS(grid, i, j+1);
        }
        if (j-1 >= 0 && (grid[i][j-1] == '1')){
            DFS(grid, i, j-1);
        }
    }
};
