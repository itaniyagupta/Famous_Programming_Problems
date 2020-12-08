// Problem statement link - https://leetcode.com/problems/minimum-path-sum/

// Time : O(m*n); Space : O(m* n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
         int m = grid.size(), n = grid[0].size();
        
        int **ans = new int*[m];
        for(int i=0; i<m; i++){
            ans[i] = new int[n];
        }
            ans[m-1][n-1] = grid[m-1][n-1]; // filling the last box of new matrix

        // Last Row
        for(int j = n-2; j>=0; j--){
            ans[m-1][j]= grid[m-1][j] + ans[m-1][j+1];
        }

        // Last Column
        for(int i = m-2; i>=0; i--){
            ans[i][n-1] = grid[i][n-1] + ans[i+1][n-1];
        }

		// filling other boxes
        for(int i= m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
               ans[i][j] = grid[i][j]+ min(ans[i][j+1], ans[i+1][j]);
            }
        }
        return ans[0][0];   // answer at first box is the minimum cost of path
    }
};