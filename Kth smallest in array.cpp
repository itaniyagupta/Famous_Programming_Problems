//Problem Statement Link - https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

// Using sorting
// Time: O(nlogn); Space : O(n) , if use heapsort then space : O(1)

class solution{
	public:
		vector<int> minJumps(vector<int>& nums, int k)
		{
		   sort(nums.begin(), nums.end());
		   return nums[k-1];
		}
};