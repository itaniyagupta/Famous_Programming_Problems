//Problem Statement Link - https://leetcode.com/problems/merge-intervals/

// Brute force
// Time : O(n^2)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		
	  vector<vector<int>>result;
	  vector<bool> merge1;
	  for(int i=0; i<intervals.size()-1; i++)
	  {
		 for(int j=i+1; j<intervals.size()-1; j++)
		 {
			 merge1[i] = merge(intervals[i], intervals[j]);
		 }
	  }
	  for(int i=0; i<intervals.size()-1; i++)
	  {
		  if(merge1[i] == false)
		  {
			  result.add(intervals[i]);
		  }
	  }
	  return result;
	}
	
	bool merge(<vector<int>& A, <vector<int>& B){
		if(A[1] < B[0] || B[1] < A[0])
		{
			return false;
		}
		B[0] = min(A[0], B[0]);
		B[1] = max(A[1], B[1]);
		
		return true;
	}
};
	  

// Time: O(nlogn); Space : O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>ans;
        vector<int> p{intervals[0][0],intervals[0][1]};
        
        for(int i=1;i<intervals.size();i++)
        {
            if(p[1]>=intervals[i][0])
            {
                p[1]=max(p[1] , intervals[i][1]);
            }
            else
            {
                ans.push_back(p);
                p[0]=intervals[i][0];
                p[1]=intervals[i][1];
            }
        }
        
        ans.push_back(p);
        return ans;
    }
};

// Inplace sorting
// Time: O(nlogn); Space : O(1)

class Solution {
public:
    vector<vector<int>> MergeIntervals(vector<vector<int>>& intervals) {
        
        intervals.sort(key = intervals[0]);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<intervals.size();i++)
        {
            if(ans[ans.size()-1][1] < intervals[i][0])
            {
              ans.add(intervals[i])
            }
            else
            {
              ans[ans.size()-1][1] = max(ans[ans.size()-1][1] , intervals[i][i])
            }
        }
        return ans;
    }
};