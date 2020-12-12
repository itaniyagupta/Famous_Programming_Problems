// Problem Statement Link - https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0; https://leetcode.com/problems/jump-game-ii/

// Brute Force solution - Recursive
// Time : O(n^n); Space : O(1)

class solution{
	public:
		vector<int> minJumps(vector<int>& nums, int curr_pos)
		{
			int n = nums.size();
			if(curr_pos > n-1)
			{
				return 0;
			}
			int minJump = INT_MAX;
			int maxsteps = nums[curr_pos];
			while(maxsteps > 0)
			{
				minJump = min(minJump, min(nums, curr_pos+maxsteps));
				maxsteps--;
			}
			return minJump;
		}
		
		vector<int> minJumps(vector<int>& nums)
		{
			return minJumps(nums,0);
		}
};

// Dynamic Programming Approach
// Time : O(n^2); Space : O(n)

class solution{
	public:
		vector<int> minJumps(vector<int>& nums){
			 int n= nums.size();
        vector<int> minJumps(n+1, INT_MAX);
        minJumps[0] = 0;
        
        for(int i=0; i<n; i++)
        {
          for(int j = i+1; j < min(i+nums[i]+1, n); j++) 
          {
            minJumps[j] = min(minJumps[j], 1 + minJumps[i]);
          }
        }
        return minJumps[n-1];
	}
};
			
// Greedy Approach
// Time : O(n); Space : O(1)

class solution{
	public:
		vector<int> minJumps(vector<int>& nums, int curr_pos)
		{	
			int prev = 0;
			int current = 0; 
			int jumps = 0;
			for(int i = 0; i < nums.size(); i++) {
				if(i > prev) {
					jumps++;
					prev = current;
				}
				current = max(current, i + nums[i]);
			}
			return jumps;
		}
};