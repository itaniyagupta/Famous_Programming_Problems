// Problem statement link - https://leetcode.com/problems/longest-increasing-subsequence/

//Recursion
// Time : O(2^n); Space : O(n)

class Solution {
public:
	int LIS(vector<int>& nums, int i)
	{
		if(i==0)
			return 1;
		int maxlen=1;
		for(int j=0;j<i;j++)
		{
			if(nums[i]>nums[j])
				maxlen=max(maxlen,1+LIS(nums,j));
		}
		return maxlen;
	}

	int lengthOfLIS(vector<int>& nums)
	{
		vector<int>ans(nums.size(),-1);
		int maxlen=1;
		for(int i=0;i<nums.size();i++) 
		{
			ans[i]=LIS(nums,i);
			maxlen=max(maxlen,ans[i]);
		}
		return maxlen;
	}
};


// Dynamic Programming
// Time : O(n^2); Space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<int> seq (n+1, 1);
        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(nums[j] < nums[i])
                {
                  seq[i] = max(seq[i], seq[j] + 1);   
                }
            }
        }
        int ans = 1;
        for(int i = 0; i<n; i++)
        {
          ans = max(ans, seq[i]);   
        }
        return ans;
    }
};

// Using Hash set
// Time : O(nlogn); Space : O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        set<int> s;        
        for(int i=0;i<n;i++){
            auto it = s.lower_bound(nums[i]);
            if(it != s.end())   
			{
				s.erase(it);
			}
            s.insert(nums[i]);
        }        
        return s.size();
    }
};