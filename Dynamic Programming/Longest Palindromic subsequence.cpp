// Problem Statement Link - https://leetcode.com/problems/longest-palindromic-subsequence/

// Dynamic Programming
// Time : O(n^2); Space : O(n)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
     
        int n = s.length();
        if(s.length() == 0)
            return 0;
        
        string str = s;
        reverse(str.begin(), str.end());
        int dp[n + 1][n + 1], ans = 1;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <=n; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(s[i - 1] == str[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};