// Problem Statement Link - https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        
         if (s == "") return s;
    
    string res = "";
    
    vector<vector<bool>> dp (s.size(), vector<bool>(s.size(), false));
    
    for (int i=s.size()-1; i>=0; --i) 
    {
        for (int j=i; j<s.size(); ++j) 
        {
            if (j == i) 
            {
                dp[i][j] = true;
            } 
            else if (j-i==1 && s[i] == s[j]) 
            {
                dp[i][j] = true;
            } 
            else if (s[i] == s[j] && dp[i+1][j-1]) 
            {
                dp[i][j] = true;
            }
                        
            if (dp[i][j]  && (j-i+1) > res.size())
            {
                res = s.substr(i, j-i+1);
            }
        }
    } 
   return res;
    }
};