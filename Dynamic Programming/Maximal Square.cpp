// Problem Statement Link - https://leetcode.com/problems/maximal-square/

// Time : O(m*n); Space : O(m*n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
                
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || matrix[0].empty())
            return 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0)
                        dp[i][j] += min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]);
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};

 // space optimized dp
 // Time : O(m*n); Space : O(n)
 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(); 
        int ans = 0;
        vector<int> dp(n+1, 0);
        for(int i = 0; i < m; i ++) 
        {
            int prev = 0;
            for(int j = 1; j <= n; j ++) 
            {
                int temp = dp[j];
                if(matrix[i][j-1] == '1')
                {
                    dp[j] = min(prev, min(dp[j], dp[j-1])) + 1;
                    ans = max(ans, dp[j]);
                }
                else dp[j] = 0;
                prev = temp;
            }
        }
     return ans*ans;
     }
};