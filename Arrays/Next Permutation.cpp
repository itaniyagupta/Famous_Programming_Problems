//Problem Statement Link - https://leetcode.com/problems/next-permutation/

// Singe Pass Approach
// Time : O(n); Space : 0(1)

class Solution {  
    public:
    void nextPermutation(vector<int>& nums) {
   
        int i = nums.size() - 1;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }
    
    private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
  
    void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size()- 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
};

// Using Library Function

class Solution {  
    public:
    void nextPermutation(vector<int>& nums) {

     bool val=next_permutation(nums.begin(),nums.end());
        if(val==false)
        {
          sort(nums.begin(),nums.end());
        }
	}
};