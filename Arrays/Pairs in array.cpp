// Problem Statement Link - https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

// Check or find all pairs on integer array whosesum is equal to given numberint

// Time: O(n^2); Space : O(1)
class solution{
		public:
			bool sumpair(vector<int>& nums)
			{
				int n = nums.size();
				for(int i=0; i<n-1; i++)
				{
					for(int j=i+1; j<n-1; j++)
					{
						if(nums[i] + nums[j] == k)
						{
							return 1;
						}
					}
				}
				return -1;
			}
};

// Sorting & Two Pointer
// Time : O(nlogn)

class solution{
		public:
			bool sumpair(vector<int>& nums)
			{
				int n = nums.size();
				sort(nums.begin(), nums.end());
				
				int low=0;
				int high = n-1;
				
				while(low<high)
				{
					if(nums[low] + nums[high] == sum)
					{
						return 1;
					}
					if(nums[low] + nums[high] > sum)
					{
						high--;
					}
					else
					{
						low++;
					}
				}
				return -1;
			}
};

// Hash Table
// Time : O(n); Space: O(n)

bool checkpair(vector<int>& nums, int k)
{
	unordered_map<int, int> map;
	for(i=0; i<nums.size(); i++)
	{
		int x = k = nums[i];
		if(map.find(x) =! map.end())
		{
			return 1;
		}
		map.insert(nums[i]);
	}
	return -1;
}
			
			
			
			