//Problem Statement Link - https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
// Time : O(nlogn), Space : O(1)

class solution{
	public:
		vector<int> getdiff(vector<int> nums, int k)
		{
			int n= nums.size();
			if(n==1)
			{
				return 0;
			}
			sort(nums.begin(), nums.end());
			
			int ans = nums[n-1] - nums[0];
			int small = nums[0] + k;
			int big = nums[n-1] - k;
			
			if(small > big)
			{
				swap(small, big);
			}
			
			for(int i=1; i<n-1; i++)
			{
				int sub = nums[i]-k;
				int add = nums[i]+k;
				
				if(sub >= small || add <= big)
				{
					continue;
				}
				if(big-sub <= add - small)
				{
					small = sub;
				}
				else
				{
					big = add;
				}
			}
			return min(ans, big-small);
		}	
};