/*
200. Number of Islands
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
    void DFSUtil(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '-' || grid[i][j] == '0') return;
        int row = grid.size();
        int col = grid[0].size();
        
        grid[i][j] = '-';
        if(i>0) DFSUtil(grid, i-1, j);
        if(j>0) DFSUtil(grid, i, j-1);
        if(i<row-1) DFSUtil(grid, i+1, j);
        if(j<col-1) DFSUtil(grid, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << grid[i][j] << endl;
                if(grid[i][j] == '1') {
                    count++;
                }
                DFSUtil(grid, i, j);
            }
        }
        return count;
        
    }
};
