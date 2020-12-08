// Problem Statement Link - https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        int **ans = new int *[m+1];
        for(int i =0; i<=m ; i++)
        {
            ans[i]=new int[n+1];
        }
        for(int j=0;j<=n;j++)
        {
        ans[0][j]=j;
        } 
        for(int i=0;i<=m;i++)
        {
          ans[i][0]=i;
        }
       
       for(int i=1;i<=m;i++)
       {
        for(int j=1;j<=n;j++)
         {
            if(word1[m-i]==word2[n-j])
            {
                ans[i][j] = ans[i-1][j-1];
            }
            else
            {
                ans[i][j]= 1 + min(ans[i-1][j-1],min(ans[i][j-1],ans[i-1][j]));
            }
        }
    }
    return ans[m][n];    
    }
};