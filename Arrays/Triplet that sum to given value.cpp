// Problem statement link - https://leetcode.com/problems/3sum/  In this problem, the given value. ie sum is 0 ; https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0
// Triplets should be unique

// Brute Force
// Time : O(n^3); Space: O(1)

	
class Solution {
	public:
	vector<vector<int>> triplet(vector<int>& nums, int sum) {
	   vector<vector<int>> arr;
	    
	   sort(nums.begin(),nums.end());
	   
		for (int i = 0; i < nums1.size() – 2; i++) {
			for (int j = i + 1; j < nums1.size() – 1; j++) 
			{
				for (int k = j + 1; k < nums1.size(); k++) 
				{
					if (nums1[i] + nums1[j] + nums1[k] == sum) 
					{
						res.add([nums1[i], nums1[j], nums1[k]])
					}
				}
			}
		}
	}
};
	
	
// Two Pointer Approach
// Time : O(n^2); Space : O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int sum) {
      vector<vector<int>> arr;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size(); i++)
        {  if(i!=0 && nums[i]==nums[i-1] ) continue;
            int j=i+1;
            int k=nums.size()-1;
         while(j<k)
            {
                 if(nums[i]+ nums[j]+ nums[k] == sum)
                 {
					 arr.push_back(vector<int>({nums[i], nums[j], nums[k]}));
					 j++;
                  while(j<k && nums[j]==nums[j-1])
                     j++;
                 }
                 else if (nums[i]+nums[j]+nums[k]<0)
                 {
                     j++;
                 }
                 else 
				 {
                     k--;
                 }
            }
          }
        return arr;
    }
};

