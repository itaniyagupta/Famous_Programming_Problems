// Problem Statement Link - https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0

// Time: O(n); Space: O(1)

class solution{
		public:
		 void rotatebyOne(vector<int>& nums){
		 
			 int n= nums.size();
			 int x = nums[n-1];
			 for(int i=n-1; i>0; i--)
			 {
				 nums[i] = nums[i-1];
				 nums[0] = x;
			 }
		 }
};