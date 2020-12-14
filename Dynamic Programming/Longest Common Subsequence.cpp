// Problem statement Link - https://leetcode.com/problems/longest-common-subsequence/
 
// Dynamic Programming 
// Time : O(n*m); Space : O(n)
 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2){
            
            int m = text1.size();
            int n = text2.size();
            int **ans = new int*[m+1];
            for(int i=0;i<=m;i++)
            {
                ans[i]=new int[n+1];
            }
            for(int i=0;i<=m;i++){
               ans[i][0]=0;
            }
            for(int j=0;j<=n;j++){
                ans[0][j]=0;
            }
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(text1[m-i]==text2[n-j]){
                        ans[i][j] = 1 + ans[i-1][j-1];
                    }
                    else{
                        ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
                    }
                }
            }
            return ans[m][n];
    }
};
 
// Recursion
class Solution {
public:
  int helper(string text1,string text2,int n,int m){
        if(n==0 || m==0){
            return 0;
        }
        else if(text1[n-1]==text2[m-1]){
            return 1+helper(DP,text1,text2,n-1,m-1);
        }
        else{
            int res1 = helper(text1,text2,n-1,m);
            int res2 = helper(text1,text2,n,m-1);
            return max(res1,res2);
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        return helper(text1,text2,n,m);
    } 
};

// Memoization
class Solution {
public:
  int helper(vector<vector<int>>&DP,string text1,string text2,int n,int m){
        if(n==0 || m==0){
            return 0;
        }
        if(DP[n][m]!=-1) return DP[n][m];
        else if(text1[n-1]==text2[m-1]){
            DP[n][m] = 1+helper(DP,text1,text2,n-1,m-1);
            return DP[n][m];
        }
        else{
            int res1 = helper(DP,text1,text2,n-1,m);
            int res2 = helper(DP,text1,text2,n,m-1);
            DP[n][m] = max(res1,res2);
            return DP[n][m];
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> DP(n+1,vector<int>(m+1,-1));
        return helper(DP,text1,text2,n,m);
    }
};
 