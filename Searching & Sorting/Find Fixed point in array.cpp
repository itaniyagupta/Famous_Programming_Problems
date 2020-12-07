// Problem statement Link - https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1

// Linear search
// Time : O(n); Space : O(1)

class solution{
public:
	int linearSearch(vector<int>& arr)  
	{   
		for(int i = 0; i < arr.size(); i++)  
		{  
			if(arr[i] == i)  
				return i;  
		}  
		return -1;  
	}
};	

// Recursive Binary Search
// Time : O(log n); Space : O(log n)
class solution{
public:
	int helper(vector<int>& arr, int low, int high)  
	{  
		if(high > = low)  
		{  
			int mid = (low + high)/2;
			if(mid == arr[mid]) 
			{				
				return mid;
			}				
			if(mid > arr[mid])
			{				
				return helper(arr, (mid + 1), high);  
			}
			else
			{
				return helper(arr, low, (mid -1));  
			}
		}  
		return -1;  
	} 
	int binarysearch(vector<int>& arr)
	{
		return helper(arr, 0, arr.size()-1);
	}
};	

// Iterative Binary Search
// Time : O(log n); Space : O(1)
class solution{
public:
	int binarySearch(vector<int>& arr) {
	  int low = 0;
	  int high= arr.size() - 1;
	  int mid;
	
	  while (low <= high) 
	  {
	     mid= (low+ high)/ 2;
	     
		 if (arr[mid] < mid) 
		 {
	       low = mid+ 1;
	     } 
		 else if (a[mid] > mid) 
		 {
	       high= mid - 1;
		 }
	     else 
		 {
          return mid;
	     }
	  }
	 return -1;
   } 
};