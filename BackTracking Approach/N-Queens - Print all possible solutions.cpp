// Problem Statement Link - https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>>res;
    int matrix[10][10] = {0};
    
    void printMat(int n)
    {
        vector<string> s(n); 
        for(int i=0;i<n;i++) {
            string tmp="";            
            for(int j=0;j<n;j++) 
            {
                if(matrix[i][j]==1) 
                {
                    tmp+="Q"; 
                } else {
                    tmp+=".";
                }
            }
            s[i]=tmp; 
        }
        res.push_back(s); 
    }
    
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
            printMat(n);
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
    
    vector<vector<string>> solveNQueens(int n) {
        solve(n, 0);
        return res;
        
    }
};
};