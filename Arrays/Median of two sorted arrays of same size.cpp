// Problem statement link - https://practice.geeksforgeeks.org/problems/find-the-median0527/1

// Count & Compare
// Time : O(n); Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
	   int size = nums1.size();	
	   int i = 0;
	   int j = 0;
	   int m1 = -1, m2 = -1 ;
	   for (count = 0; count<size; count++) 
	   {
		  if (i == size) {
			 m1 = m2;
			 m2 = nums2[0];
			 break
		  } 
		  else if (j == size) 
		  {
			 m1 = m2;
			 m2 = nums1[0];
			 break
		  } 
		  if (num1[i] < num2[j]) 
		  { 
			 m1 = m2;
			 m2 = nums1[i]; 
			 i++;
		  } else 
		  { 
			 m1 = m2
			 m2 = nums2[j]
			 j++;
		  }
	   }
	   return (m1 + m2)/2;
	}
};

// Comparing medians
// Time : O(log n); Space: O(log n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		 
		  int size = nums1.size();
		   if (size <= 0)
			  return -1;
		   if (size == 1)
			  return (nums1[0] + nums2[0]) / 2;
		   if (size == 2)
			  return (max(nums1[0], nums2[0]) + min(nums1[1], nums2[1])) / 2;
		  
		   int med1 = median(nums1, size);
		   int med2 = median(nums2, size);
		   
		   if (med1 == med2)
			  return med1; 
		   if (med1 < med2)
		   {
			  if (size % 2 == 0)
				 return findMedianSortedArrays(nums1 + size/2 - 1, nums2, size - size/2 + 1);
			  else
				 return findMedianSortedArrays(nums1 + size / 2, nums2, size - size / 2);
		   } 
		   else 
		   {
			  if (size % 2 == 0)
				 return findMedianSortedArrays(nums2 + size / 2 - 1, nums1, size - size / 2 + 1) ;
			  else
				 return findMedianSortedArrays(nums2 + size / 2, nums1, size - size / 2) ;
		   }
	}
	
	int median(vector<int>& nums, int size) { 
	   if (size % 2 == 0)
		  return (nums[size/2] + nums[size/2 - 1])/2;
	   else
		  return nums[size/2];
    }
};

