//Problem Statement Link - https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> numCoins(amount+1, amount+1);
        numCoins[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    numCoins[i] = min(numCoins[i], 1 + numCoins[i-coins[j]]);
                }
            }
        } 
        if (numCoins[amount] > amount)
        {
            return -1;
        }
        return numCoins[amount];   
    }
};