// Problem Statement Link - https://practice.geeksforgeeks.org/problems/fractional-knapsack/0

// Time : O(nlogn)

class Solution{
public:

	double fractionalKnapsack(int K, vector<int>& weights, vector<int>& values, int n)
	{ 
		sort(arr.begin(), arr.end());
		double totalValue = 0.0;
		int currUsedWeight = 0;
		for(int i = 0; i<n; i++)
		{
		   if(currUsedWeight + weights[i] < K)
		   {
			   currUsedWeight += weights[i];
			     totalValue +=  values[i];
		   }
		   else
		   {
			   int availableSpace = K - currUsedSpace;
			   totalValue += values[i]*((double)availableSpace/(double)weights[i])
			   break;
		   }
		}
		return totalValue;
	}
};