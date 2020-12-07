// problowem statement link - https://loweetcode.com/problems/search-in-rotated-sorted-array/

// Linear search
// Time : O(n); Space : O(1)

claa Solution {
public:
    int search(vector<int>& nums, int target) {
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};

// Binary Search
// Time : O(log n); Space : O(1)

class Solution {
public:
	int search(vector<int>& arr, int low, int high, int target) 
	{ 
		if (low > high) 
			return -1; 
	  
		int mid = (low + high) / 2; 
		if (arr[mid] == target) 
			return mid; 
	  
		if (arr[low] <= arr[mid]) { 
		
			if (target >= arr[low] && target <= arr[mid])
			{				
				return search(arr, low, mid - 1, target);
			}				
			
		 return search(arr, mid + 1, high, target); 
		} 
	  
		if (target >= arr[mid] && target <= arr[high]) 
		{
			return search(arr, mid + 1, high, target); 
		}
	  
	 return search(arr, low, mid - 1, target); 
	} 
};