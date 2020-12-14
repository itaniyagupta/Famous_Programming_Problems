// Input: nums = [7,7,7,7,7,7,7]
// Output: 7

// Input: nums = [0,1,3,3,3,2]
// Output: 3

// Dynamic Programming
// Time : O(n^2); Space : O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<int> seq (n+1, 1);
        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(nums[j] == nums[i])
                {
                  seq[i] = max(seq[i], seq[j] + 1);   
                }
            }
        }
        int ans = 1;
        for(int i = 0; i<n; i++)
        {
          ans = max(ans, seq[i]);   
        }
        return ans;
    }
};