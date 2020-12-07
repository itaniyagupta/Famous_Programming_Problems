// Linear Search
// Time :(√ n); Space: O(1)

class solution{
	public:
		int floorSqrt(int x) 
		{ 
			if (x == 0 || x == 1) 
			return x; 
		
			int i = 1, result = 1; 
			while (result <= x) 
			{ 
			  i++; 
			  result = i * i; 
			} 
			return i - 1; 
		} 
};

// Binary Search
// Time :  O(log n); Space : O(1)

class solution{
	public:
	  int floorSqrt(int x)  
	   {     
			if (x == 0 || x == 1)  
			   return x; 
		  
			int start = 1, end = x, ans;    
			while (start <= end)  
			{         
				int mid = (start + end) / 2; 
		  
				if (mid*mid == x) 
					return mid; 
		 
				if (mid*mid < x)  
				{ 
					start = mid + 1; 
					ans = mid; 
				}  
				else 
				{
					end = mid-1;
				}					
			} 
			return ans; 
	   }
};		