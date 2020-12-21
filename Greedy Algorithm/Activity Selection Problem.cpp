//Problem Statement  Link 

// Time -  O(n log n)
class Solution {
public:
     static bool cmp(vector<int>&a , vector<int>&b) {
        return a[1]<b[1];
    }
	int MaxActivities(vector<int> activity, int n) 
	{ 
		sort(activity.begin(),activity.end(),cmp);
		int i, j; 
		i = 0; 
		int ans=1;
	   
		for (j = 1; j < n; j++) 
		{ 
		  if (s[j] >= f[i]) 
		  { 
			  ans++
			  i = j; 
		  } 
		} 
	  return ans;
	}
};