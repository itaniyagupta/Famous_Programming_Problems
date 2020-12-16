// Problem Statement Link - https://leetcode.com/problems/n-queens-ii/

int ans;
    int matrix[10][10] = {0};
    
    bool isPossible(int n, int row,int col) {
                                  // column check
            for(int i= row-1;i>=0; i--) 
            { 
                if(matrix[i][col]==1)
                    return false;
            }

                                  // left diagonal
            int i=row-1,j=col-1;
            while(i>=0 && j>=0) 
            {
                if(matrix[i][j]==1) 
                    return false;
                i--;j--;
            }
                                 // right diagonal 
            i=row-1,j=col+1;
            while(i>=0 && j<=n) 
            {
                if(matrix[i][j]==1) 
                    return false;
                i--;j++;
            }

      return true;
    }
    
    void solve(int n, int row){
        if(row==n) 
        {
          ans++;
        }
        for(int col=0;col<n;col++) {
            if(isPossible(n,row,col)) 
            { 
                matrix[row][col]=1; 
                solve(n,row+1);
                matrix[row][col]=0;
            }
        }
        return;
    }
    
    
    int totalNQueens(int n) {
        solve(n, 0);
        return ans;
    }
};