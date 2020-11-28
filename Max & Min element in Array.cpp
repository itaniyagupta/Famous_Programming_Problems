// Linear Search Approach
	// Time: O(n); Space: O(1)

class Solution {  
    public:
   
    int minmax(vector<int>& nums) {
		int min, max;
		min = max = nums[0];
		
		for(int i=1; i<nums.size(); i++)
		{
			if(min > nums[i])
			{
				min = nums[i];
			}
			if(max < nums[i])
			{
				max = nums[i];
			}
		}
		return min, max;
	}
};

// Using Sorting
	// Time : O(nlogn); space: O(1)
	
	class Solution {  
    public:
   
    int minmax(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int min = nums[0];
		int max = nums[nums.size()-1];
		
	 return min, max;
	 }
};
	


// Using STL

class Solution {  
    public:
   
    int minmax(vector<int>& nums) {
		int n= nums.size();
		int x = min_element(nums, nums+n);
		int y =  max_element(nums, nums+n);
		
		return x , y;
	}
};