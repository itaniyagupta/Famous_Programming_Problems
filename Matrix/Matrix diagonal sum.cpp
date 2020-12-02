// Problem statement link - https://leetcode.com/problems/matrix-diagonal-sum/

// Time: O(m*n); Space: O(1)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int m =mat.size();
        int n= mat[0].size();
        int i = 0, j = n-1;
        int sum = 0;
        for(int k = 0; k < m; k++)
        {
            for(int l = 0; l <n; l++)
            {
                if(l==i||l==j)
                {
                    sum+=mat[i][l];
                }
            }
                
            i+=1;
            j-=1;
        }
        return sum;
        
        
        
    }
};