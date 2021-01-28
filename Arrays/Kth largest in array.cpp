// Problem Statement Link - https://leetcode.com/problems/kth-largest-element-in-an-array/

// Using sorting
// Time: O(nlogn); Space : O(n) , if use heapsort then space : O(1)

class solution{
	public:
		int findKthLargest(vector<int>& nums, int k)
		{
		   int n= nums.size();
		   sort(nums.begin(), nums.end());
		   return nums[n-k];
		}
};