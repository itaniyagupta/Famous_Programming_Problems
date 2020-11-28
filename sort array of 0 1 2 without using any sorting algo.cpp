//Problem Statement Link - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0 ; https://leetcode.com/problems/sort-colors
/* Sort an array of 0s, 1s and 2s
   Given an array A[] consisting 0s, 1s and 2s. 
   The task is to write a function that sorts the given array. 
   Functions should put all 0s first, then all 1s & all 2s in last.
   */
   
// Simple Counting
// Time: O(n); Space: O(1)

class solution{
		public:
			void sortarr(vector<int>& nums)
			{
				int c1 =0, c2 =0, c3=0;
				
				for(int i=0; i<nums.size(); i++)
				{
					switch(nums[i]){
						case 0 : c1++;
						break;
						case 1 : c2++;
						break;
						case 2 : c3++;
						break;
					}
				}
				int j=0;
				while(c1>0){
					nums[j++]=0;
					c1--;
				}
				while(c2>0){
					nums[j++]=1;
					c2--;
				}
				while(c3>0){
					nums[j++]=2;
					c3--;
				}
			}
};

// Dutch national flag problem algorithm
// Time: O(n); Space: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
      
        int low = 0, mid = 0; 
        int high = nums.size()-1;
        
        while(mid < high)
        {
            switch (nums[mid])
            {
                case 0: 
                swap(nums[low++], nums[mid++]); 
                break; 

                case 1: 
                  mid++; 
                  break; 

                case 2: 
                  swap(nums[mid], nums[high--]); 
                  break;      
            }          
        }
    }
};
