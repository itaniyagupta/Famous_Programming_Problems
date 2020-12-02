// Problem Statement Link - https://leetcode.com/problems/maximum-subarray/ ; https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// Brute Force Solution
// Time : O(n^3); Space : O(1)

class solution{
	public:
		
		vector<int> maxsubarraysum(vector<int>& nums)
		{
			int max_sum =0;
			for(int i=0; i< nums.size()-1; i++)
			{
				for(int j=i; j<nums.size()-1; j++)
				{
					int sum =0;
					for(k=i; k<j; k++)
					{
						sum = sum + nums[k];
					}
					if(sum > max_sum){
						max_sum = sum;
					}
				}
			}
			return max_sum;
		}
};

// Another Brute Force Solution
// Time : O(n^2); Space : O(1)

class solution{
	public:
	
		vector<int> maxsubarraysum(vector<int>& nums)
		{
			int max_sum =0;
			for(int i=0; i< nums.size()-1; i++)
			{	
				int sum =0;
				for(int j=i; j<nums.size()-1; j++)
				{
					sum = sum + nums[j];
					if(sum > max_sum){
						max_sum = sum;
					}
				}
			}
			return max_sum;
		}
};

// Divide & Conquer Algorithm
// Time : O(nlogn); Space: O(nlogn)

class solution{
	public:
	  vector<int> maxsubarraysum(vector<int>& nums, int low, int high)
		{
			if(low  == high)
			{
				return nums[low];
			}
			else{
				int mid = low + (high-low)/2;
				int leftsum = maxsubarraysum(nums,low,mid);
				int rightsum = maxsubarraysum(nums, mid+1, high);
				int crossingsum = maxcrossingsum(nums, low, mid, high);
				
				return max(leftsum, rightsum, crossingsum);
			}
		}
		vector<int> maxcrossingsum(vector<int>& nums, int left, int mid, int right)
		{
			int sum=0;
			int leftsum = INT_MIN;
			for(int i=left; i<mid; i++)
			{
				sum = sum + nums[i];
				if(sum > leftsum)
				{
					leftsum = sum;
				}
			}
			sum=0;
			int rightsum = INT_MIN;
			for(int i=mid+1; i<right; i++)
			{
				sum = sum + nums[i];
				if(sum > rightsum)
				{
					rightsum = sum;
				}
			}
			return (leftsum + rightsum);
		}
		vector<int> largestsubarraysum(vector<int>& nums)
		{
			int low = 0;
			int high = nums.size()-1;
			
			return maxsubarraysum(nums, low, high);
		}
};
		
// Dynamic Programming - using Auxiliary Array
// Time : O(n), Space: O(n)

class solution{
	public:
	  vector<int> maxsubarraysum(vector<int>& nums)
		{
			int n = nums.size();
			int max_end_here[n];
			max_end_here[0] = nums[0];
			
			for(int i=1; i<n-1; i++)
			{
				if(nums[i] + max_end_here > 0)
				{
					max_end_here[i] = nums[i] + max_end_here[i-1];
				}
				else{
					max_end_here = nums[i];
				}
			}
			int ans =0;
			for(int i=0; i<n-1; i++)
			{
				ans = max(ans, max_end_here[i]);
			}
			return ans;
		}
};


// Dynamic Programming - using Kadane's Algorithm
// Time : O(n), Space: O(1)

class solution{
	public:
	  vector<int> maxsubarraysum(vector<int>& nums)
		{
			int n = nums.size();
			int max_so_far = 0;
			int max_end_here = 0;
			
			for(int i=0; i<n-1; i++)
			{
				max_end_here += nums[i];
				if(max_end_here < 0)
				{
					max_end_here=0;
				}
				max_so_far = max(max_so_far, max_end_here);
			}
			return max_so_far;
		}
};

// Kadane wont work if all elements are negative. So, for all negative elements, following is the code
// Time : O(n), Space: O(1)

class solution{
	public:
	  vector<int> maxsubarraysum(vector<int>& nums)
		{
			int n = nums.size();
			int max_so_far, curr_sum;
			max_so_far = curr_sum = nums[0];
			
			for(int i=1; i<n; i++)
			{
				curr_sum = max(nums[i], nums[i]+curr_sum);
				max_so_far = max(max_so_far, curr_sum);
			}
			return max_so_far;
		}
};