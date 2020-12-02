// Problem Statement Link - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Using priority queue
// Time : O(klogn); Space : O(n)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      
        
           vector<int> v;                                                 //Store 2D matrix -> 1D array
           for(int i=0;i<matrix.size();i++)                                   
           {
             for(int j=0;j<matrix.size();j++)                            
             {
                 v.push_back(matrix[i][j]);                                 
             }
           }
          priority_queue<int> ans;                                 // max heap because we need to find smallest 
                                                                // in max heap all greater element is popped out
          for(int i=0;i<v.size();i++)
          {
            ans.push(v[i]);                                              
            if(ans.size()>k)                                            // whenever size of heap exceed we need to pop
            {
                ans.pop();                                            
            }
         }
         return ans.top();  
	}
};

// Binary Search		
// Time : O(nlog(n)); Space: O(1)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int start = matrix[0][0];
        int end = matrix[n-1][n-1];
       
        while(start < end) {
            int cnt = 0, j;
            int mid = (start+end)/2;
            for (int row = 0; row<n; row++) {
                   j = n-1;
                while(j >= 0 and matrix[row][j] > mid) {
                    j--;
                }
                
                cnt += (j+1);
            }
            
            if (cnt < k) {
        
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        return start;
        
    }
};