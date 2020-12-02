//  Problem Statement Link - https://leetcode.com/problems/longest-consecutive-sequence/

// Sorting
// Time : O(nlogn)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		int longest_streak = 0;
		int i=0
		while(i<n)
		{
			int curr_streak = 1;
			while(i<n && nums[i+1] = nums[i]+i)
			{
				curr_streak++;
				i++;
			}
			if(curr_streak == 1)
			{
				i++;
			}
			longest_streak = max(longest_streak, curr_streak);
		}
		return longest_streak;
	}
};

// using hash set
// Time : O(n);

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int>s;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
           
            if(s.find(nums[i]-1) == s.end()){
                int j = nums[i];
               
                while(s.find(j) != s.end())
                    j++;
             
                ans = max(ans, j-nums[i]);
            }
        }
        return ans;
    }
};




