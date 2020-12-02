// Problem Statement Link - https://leetcode.com/problems/trapping-rain-water/

// Brute Force
// Time : O(n^2); Space: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
      	 int maxWater = 0;
       int rightHeight, leftHeight;
		for (int i = 1; i<height.size()-1; i++) 
		{
			leftHeight = height[i];
			for (int j = 0; j<i; j++)
			{
				leftHeight = max(leftHeight, height[j]);
			    rightHeight = height[i];
			}
			for (int j = i+1; j<height.size(); j++) 
			{
				rightHeight = max(rightHeight, height[j]);
			}
			maxWater = maxWater + (min(leftHeight, rightHeight) - height[i]);
		}
	return maxWater;
	}
};

// Dynamic Programming
// Time : O(n); Space: O(n)

class Solution {
 public:
    int trap(vector<int>& height) {
		int maxWater = 0;
		int size =  height.size();
		int left_max[size], right_max[size];
		    left_max[0] = height[0];
			for (int i = 1; i<size; i++) 
			{
				left_max[i] = max(height[i], left_max[i - 1]);
			}
			right_max[size - 1] = height[size - 1];
			for (int i = size - 2; i >= 0; i--) 
			{
				right_max[i] = max(height[i], right_max[i + 1]);
			}
			for (int i = 1; i<size-1; i++) 
			{
				maxWater += min(left_max[i], right_max[i]) - height[i];
			}
	    return maxWater;
	}
};

// Two Pointer 
// Time: o(n); o(1)

class Solution {
 public:
    int trap(vector<int>& height) {
	  
	  int low = 0, high = height.size() - 1;
	  int leftMax = 0, rightMax = 0;
	  int max_water = 0;
	  while (low < high) {
		if (height[low] > leftMax)
		{			
			leftMax = height[low];
		}
		if (height[high] > rightMax) 
		{
			rightMax = height[high];
		}
		if (leftMax < rightMax) { 
	
			max_water += (leftMax - height[low]);
			low++;
		} 
		else 
		{
			max_water += (rightMax - height[high]);
			high--;
		}
	  }
	  return max_water;
	}
};