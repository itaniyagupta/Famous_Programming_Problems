//Problem Statement Link - https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

// Using sorting
// Time: O(nlogn); Space : O(n) , if use heapsort then space : O(1)

class solution{
	public:
		int KthSmallest(vector<int>& nums, int k)
		{
		   sort(nums.begin(), nums.end());
		   return nums[k-1];
		}
};

//QuickSelect

class solution{
	public:
		int partition(vector<int>& nums, int l, int r) { 
				int x = nums[r], i = l; 
				for (int j = l; j <= r - 1; j++) { 
					if (nums[j] <= x) 
					{ 
						swap(&nums[i], &nums[j]); 
						i++; 
					} 
				} 
				swap(&nums[i], &nums[r]); 
				return i; 
		}
		int Ksmall(vector<int>& nums, int l, int r, int k){
			
			if (k > 0 && k <= r - l + 1) 
			{ 
				int pos = partition(nums, l, r); 
		  
				// If position is same as k 
				if (pos - l == k - 1) 
					return nums[pos]; 
				
				// If position is more, recur left subarray 
				if (pos - l > k - 1) 
					return Ksmall(nums, l, pos - 1, k); 
		  
				// Else recur right subarray 
				return Ksmall(nums, pos + 1, r, k - pos + l - 1); 
		   } 
	  
			// If k is more than number of elements in array 
			return INT_MAX; 
		}
		
		int KthSmallest(vector<int>& nums, int k)
		{
		   int n= nums.size();
		   Ksmall(nums, 0, n-1, k);
		}
};