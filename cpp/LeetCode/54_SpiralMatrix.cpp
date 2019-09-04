// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// Example 1:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        
        res.resize(matrix.size() * matrix.front().size());
        auto r = res.begin(); 
        
        int startRow=0, endRow = matrix.size()-1;
        int startCol = 0, endCol = matrix.front().size()-1;

        while(r < res.end()) {
            
            for (int i=startCol; i<=endCol; i++, r++)
                *r = matrix[startRow][i];
            if (r == res.end())
                return res;
            startRow++;
            
            for (int i=startRow; i<=endRow; i++, r++)
                *r = matrix[i][endCol];
            if (r == res.end())
                return res;
            endCol--;
            
            for (int i=endCol; i>=startCol; i--, r++)
                *r = matrix[endRow][i];
            if (r == res.end())
                return res;
            endRow--;
            
            for (int i=endRow; i>=startRow; i--, r++) 
                *r = matrix[i][startCol];
            if (r == res.end())
                return res;
            startCol++;
        }
        
        return res;
    }
};