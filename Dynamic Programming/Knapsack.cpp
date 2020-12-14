// Problem Statement Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

// Recursion
// Time : O(2^n)

class Solution{
public:

	int knapsack(vector<int>& weight, vector<int>& values, int maxweight, int n){
		
		if(n==0 || maxweight == 0)
		{
			return 0;
		}
		// including ist element in knapsack
		if(weight[0] > maxweight)
		{
			return knapsack(weight+1, values+1, n-1, maxweight);
		}
		int x = knapsack(weight+1, values+1, n-1, maxweight-weight[0])+values[0];

		// not incl. ist element
		int y = knapsack(weight+1, values+1, n-1, maxweight);

		return max(x,y);
	}
};

// Dynamic Programming
// Time : O(N*W), Space : O(N*W)  where N is number of weight element & W is maxweight

int knapSack(int maxweight, vector<int>& weight, vector<int>& values, int n) 
{ 
    vector<int> arr (n + 1, maxweight + 1); 
  
    for (int i = 0; i <= n; i++)  
    { 
        for (int j = 0; j <= maxweight; j++)  
        { 
            if (i == 0 ||j == 0)
			{				
                arr[i][j] = 0; 
			}
            else if (weight[i - 1] <= j)
			{				
               arr[i][j] = max(val[i - 1] + arr[i - 1][j - weight[i - 1]], arr[i - 1][j]); 
			}
            else
			{
               arr[i][j] = arr[i - 1][j]; 
			}
        } 
    } 
    return arr[n][maxweight]; 
}