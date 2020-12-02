// Problem Statement Link - https://leetcode.com/problems/set-matrix-zeroes/

// Space - O(m*n)

class Solution {
public:
    void nullifyRow(vector<vector<int>>& matrix, int row) {
         for (int j = 0; j < matrix[0].size(); j++) 
         {
         matrix[row][j] = 0;
         }
    }

    void nullifycolumn(vector<vector<int>>& matrix, int col) {
        for (int i= 0; i < matrix.size(); i++)
        {
        matrix[i][col] = 0;      
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<bool> row;
        vector<bool> column;
        // bool* row = new bool[matrix.size()];
        // bool* column = new bool[matrix[0].size()];
        
    for (int i= 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size();j++) {
                if (matrix[i][j] == 0) {
                        row[i] = true;
                        column[j] = true;
                }
          }
      }
    
    for (int i= 0; i < row.size(); i++) {   
        if (row[i]) 
        {
            nullifyRow(matrix, i);
        }
    }
    for (int j= 0; j < column.size(); j++) {   
        if (column[j]) 
        {
            nullifycolumn(matrix, j);
        }
     }
    
  }
};


// Space - O(m +n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<bool> row(n, false);
        vector<bool> col(m, false);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                
                if(!matrix[i][j]){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                
                if(row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
        
    }
};

// Space - O(1)

class Solution
{
public:
    void setZeroes( vector<vector<int>>& arr )
    {
        int col0 = 1, row = arr.size(), col = arr[ 0 ].size() ;
        for( int i = 0 ; i < row ; i ++ )
        {
            if( arr[ i ][ 0 ] == 0 ) col0 = 0 ;
            for( int j = 1 ; j < col ; j ++ )
            {
                if( arr[ i ][ j ] == 0 ) arr[ i ][ 0 ] = arr[ 0 ][ j ] = 0 ;
            }
        }

        for( int i = row - 1 ; i >= 0 ; i -- )
        {
            for( int j = col - 1 ; j >= 1 ; j -- )
            {
                if( arr[ i ][ 0 ] == 0 || arr[ 0 ][ j ] == 0 )
                {
                    arr[ i ][ j ] = 0 ;
                }
            }
            if( col0 == 0 ) arr[ i ][ 0 ] = 0 ;
        }
    }
};