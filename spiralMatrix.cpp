/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }
        int rowEnd = matrix.size()-1;
        int colEnd = matrix[0].size()-1;
        
        int rowStart = 0;
        int colStart = 0;
        
        while(rowStart <= rowEnd && colStart <= colEnd) {
            //left -> right
            for(int j = colStart; j <= colEnd; j++) {
                result.push_back(matrix[rowStart][j]);
            }
            rowStart++;
            
            for(int j = rowStart; j <= rowEnd; j++) {
                result.push_back(matrix[j][colEnd]);
            }    
            colEnd--;
            
            if(rowStart <= rowEnd) {
              for(int j=colEnd; j >= colStart; j--){
                result.push_back(matrix[rowEnd][j]);
              }
            }    
            rowEnd--;
            
            if(colStart <= colEnd) {
              for(int j=rowEnd; j >= rowStart; j--){
                result.push_back(matrix[j][colStart]);
              }
            }    
            colStart++;
        }
        return result;
        
    }
};
