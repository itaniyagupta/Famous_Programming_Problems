//  Problem Statement Link - https://practice.geeksforgeeks.org/problems/inversion-of-array/0

// Simple Approach
// Time : O(n^2); Space: O(1)

class Solution {
	public:
		int getInversions(vector<int>& nums) {
			int inv_count =0;
			for(int i=0; i<nums.size()-1; i++)
			{
				for(int j=i+1; j<nums.size(); j++)
				{
					if(nums[i] > nums[j])
					{
						inv_count++;
					}
				}
			}
			return inv_count;
	}
};

// Divide & Conquer
// Time : O(nlogn); Space: O(n)

class Solution {
	public:

		int merge(vector<int> nums, vector<int> temp, int start, int mid, int end)
		{
			int i= start;
			int j= mid;
			int k= start;
			
			int inv_count = 0;
			while(i<= mid-1 && j<end)
			{
				if(nums[i] < nums[j])
				{
					temp[k++] = nums[i++];
				}
				else
				{
					inv_count += mid -1;
					temp[k++] = nums[j++];
				}
			}
			while(i<mid-1)
			{
				temp [k++] = nums[i++];
			}
			while(j<end)
			{
				temp[k++] = nums[j++];
			}
			for(int i=start; i<=end; i++)
			{
				nums[i] = temp[i];
			}
			return inv_count;
		}
		
		int mergesort(vector<int> nums, vector<int> temp, int start, int end)
		{
			int inv_count =0;
			if(start < end)
			{
				int mid = (start+end)/2;
				inv_count += mergesort(nums, temp, start, mid);
				inv_count += mergesort(nums, temp, mid+1, end);
				inv_count += merge(nums, temp, start, mid+1, end);
			}
			return inv_count;
		}	
					
		int getInversions(vector<int>& nums) {
			int n= nums.size();
			vector<int> temp;
			
			return mergesort(nums, temp, 0, n-1);
		}	
	}
	
};
