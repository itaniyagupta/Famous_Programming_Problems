//Problem Statement  Link - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Time -  O(n log n)
class Solution {
public:
     static bool cmp(vector<int>&a , vector<int>&b) {
        return a[1]<b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);
        int n=points.size();
        if(n<2) return n;
        int ans=1; 
        int i=0; 
        for(int j=1;j<n;j++) 
        {
            if(points[j][0]>points[i][1]) 
            {    
                ans++;
                 i=j;
            }
        }
        return ans;
    }
};