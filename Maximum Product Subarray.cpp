// Problem Statement Link - https://leetcode.com/problems/maximum-product-subarray/

// Brute Force
// Time: O(N^2); Space : O(1)		

class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
		int maxsofar = nums[0];
    
        for (int i = 0; i < nums.size(); i++)
        {
              int product = nums[i];
               for (int j = i+1; j < nums.size(); j++) 
               {
                    maxsofar = max(maxsofar, product);
                    product *= nums[j];
               }
          maxsofar = max(product, maxsofar);  // for n-1 index - contiguous array
        }
    
         return maxsofar;
    }
};


// Dyanmic Programming
// Time: O(n); Space : O(1)


class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
         if(nums.size() == 0)
        {
            return 0;
        }
        
        int minEndingHere = nums[0];
        int maxEndingHere = nums[0];
        int maxSoFar = nums[0];
        
		for(int i = 1; i < nums.size(); i++)
        {
            int temp = maxEndingHere;
            maxEndingHere = max(maxEndingHere*nums[i], max(nums[i], minEndingHere*nums[i]));
            minEndingHere = min(minEndingHere*nums[i], min(nums[i], nums[i]*temp));
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};