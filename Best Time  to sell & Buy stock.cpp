// Problem Statement Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// Brute Force
// Time: O(n^2); Space : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices, int start, int end) {
		
		if(end <= start)
		{
			return 0;
		}
		int profit = 0;
		for(int i = start; i<end; i++)
		{
			for(int j=i+1; j<=end; j++)
			{
				if(prices[j] > prices[i]){
					int curr_profit = prices[j] - prices[i] + maxProfit(prices, start, i-1); + maxProfit(prices, j+1, end);
					int profit = max(profit, curr_profit);
				}
			}
		}
		return profit;
	}
};
		
// if allowed to buy stock only once use following approach
// Time  : O(n)

class Solution {
public:
	void stockbuysell(vector<int>& price){
		int n = price.size();
		
		if(n==1)
		{
			retrn;
		}
		
		int i=0;
		while(i<n-1)
			while((i< n-1) && price[i+1] < price[i])
				i++;
				if(i== n-1)
					break;
				int buy = i++;
			while(i<n && price[i] > price[i-1])
				i++;
				int sell = i-1;
		
		return sell, buy;
	}
};

				
// Efficient Approach
// Time : O(n); Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int maxP = 0;
        int minP = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
        {
            minP = min(minP, prices[i]);
            maxP = max(maxP, prices[i] - minP);
        }
    return maxP;
    }
};       
       