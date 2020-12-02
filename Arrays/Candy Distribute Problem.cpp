// problem statement link - https://leetcode.com/problems/candy/

// Brute Force
// Time :  O(n²); Space : O(n)

class Solution {
public:
    int candy(vector<int>& ratings) {
       
	   int n= ratings.size();
         vector<int> candies(n,1);
        bool flag = true;
        while (flag) 
        {
            flag = false;
            for (int i = 0; i<ratings.size(); i++)
            {
                if (i != ratings.size() - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    flag = true;
                }
                if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    flag = true;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < ratings.size(); i++)
        {
            sum += candies[i];
        }
        return sum;
        
    }
};

// Greedy Approach
// Time :  O(n); Space : O(n)

class Solution {
public:
    int candy(vector<int>& ratings) {
           
        int n = ratings.size();
            vector<int> L2R(n,1);
                          // considering only left neighbours
            for (int i = 1; i < n; i++)
                if (ratings[i] > ratings[i-1])
                    L2R[i] = L2R[i-1]+1;
            vector<int> R2L(n,1);
                        // considering only right neighbours
            for (int i = n-2; i >= 0; i--)
                if (ratings[i] > ratings[i+1])
                    R2L[i] = R2L[i+1]+1;
            int sum = 0;
                         // considering both neighbours
            for (int i = 0; i < n; i++)
                sum += max(L2R[i], R2L[i]);
            return sum;
    }
};