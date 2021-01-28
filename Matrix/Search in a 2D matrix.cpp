// Problem Statement Link - https://leetcode.com/problems/search-a-2d-matrix/

// Brute Force
// Time : O(m*n); Space: O(1)

class Solution {
 public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0 && target == 0)
        {
            return false;
        }
        
        int m= matrix.size();
        int n= matrix[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0;j<n; j++)
            {
                if(matrix[i][j] == target)
                {
                    return true;
                }
            }
        }    
    return false;
    }
};

// Row-Column remove
// Time : O(m + n); Space : O(1)  

class Solution {
 public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		 if(matrix.size() == 0 && target == 0)
        {
            return false;
        }
        
        int smallest = matrix[0][0], largest = matrix[matrix.size() - 1][matrix.size() - 1]; 
        if (target < smallest || target > largest) 
             return false;
		 
		int m = matrix.size();
		int n = matrix[0].size();
		int row = 0,col = n-1;
		while(row < m and col >= 0)
		{
			if(matrix[row][col] == target)
				return true;
			else if(matrix[row][col] < target)
			{
				row++;
			}
			else 
			{
				col--;
			}
		}
		return false;
	}
};

// Binary Search
// Time: O(log(m*n)); Space: O(log(m) + log(n))

class Solution {
 public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();
		int l = 0, r = m * n - 1;
		
		while (l < r)
		{
			mid = (l + r - 1) / 2;
			
			if (matrix[mid / m][mid % m] < target)
			{
				l = mid + 1;
			}
			else 
			{
				r = mid;
			}
		}
		if( matrix[r / m][r % m] == target )  // An array can be converted into n * m matrix: a[x] → matrix[x / m][x % m]
			return true;
		else
			return false;
	}
};