// Problem statement link - https://leetcode.com/problems/first-missing-positive/

// Brute force
// Time : O(n^2); Space : O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int ans;
        for(int i = 1; i<nums.size()+1; i++)
       {
        bool flag = false;
            for(int j = 0;j<nums.size()-1; j++)
            {
                if(nums[j] == i)
                {
                    flag = true;
                    break;
                }
            }
            if(flag == false)
            ans = i;   
        }
     return ans;
    }
};

// sorting & then searching
// Time : O(nlogn); Space : O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     
        sort(nums.begin(), nums.end());
        int small = 1;
        for(int i = 1; i<nums.size(); i++)
        {
            if(small > nums[i]) 
                continue;
            if(small == nums[i])
                small++;
            if(nums[i] > small)
                return small;
        }
    return small;    
    }
};

// Hash Table
// Time : O(n); Space : O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    
        int ans;
        unordered_map<int,int> Hash;
        for(int i = 0; i< nums.size()-1; i++)
        {
         Hash[nums[i]] = true;   
        }
        
        for(int i = 1; i<nums.size()+1; i++)
        {
            if(Hash.find(i) ==  Hash.end())
               ans = i;
        }
        return ans;
    }        
};

// Inplace Hashing

class Solution {
    public:
        int segregate(vector<int>& nums)
        {
            int j = nums.size()-1, i = 0;
            while( i <= j )
            {
                if(nums[i] <= 0)
                {
                    swap(nums[i], nums[j]); 
                    j--;
                }
                else
                    i++;
            }
            return i;
        } 

        int firstMissingPositive(vector<int>& nums) {
             int N = segregate(nums);
            for (int k = 0; k <N; k++)
            {
                if(abs(nums[k]) - 1 < N)
                   nums[abs(nums[k]) - 1] = - abs(nums[abs(nums[k]) - 1]);
            }
            for(int k = 0; k <N; k++)
            { 
                if(nums[k] > 0)
                    return k + 1;
            }
            return N + 1;
        }
};
