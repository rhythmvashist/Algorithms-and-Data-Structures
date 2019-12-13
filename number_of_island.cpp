/*
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
# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    void bfstraversal(vector<vector<char>> grid, int i ,int j){
      if(i<0 ||j<0|| j>=grid[i].size()||i>grid.size()||grid[i][j]=='0'){
        return ;
      }
      grid[i][j]= '0';
      bfstraversal(grid,i+1,j);
      bfstraversal(grid,i,j+1);
      bfstraversal(grid,i-1,j);
      bfstraversal(grid,i,j-1);

    }

    int numIslands(vector<vector<char>>& grid) {
      int count=0;
      for(int i=0;i<grid.size();i++){
        for(int j=0;grid[i].size();j++){
          if(grid[i][j]=='1'){
            count++;
            bfstraversal(grid,i,j);
          }
          
        }
      }
      return count ;
        
    }
};