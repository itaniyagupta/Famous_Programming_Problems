
// time : O(nlogn); space: O(1)
class Solution {
public:
	int sol(vector<int>arr, int n, int k)
	{
		sort(arr, arr + n);
		int sum = 0;
		int i = 0;
		 
		while (k > 0) 
		{
			if (arr[i] == 0)
				k = 0;
			else
			{
				arr[i] = (-1) * arr[i];
				k = k - 1;
			}
			i++;
		}
	 
		for(int j = 0; j < n; j++) 
		{
			sum += arr[j];
		}
		return sum;
	}
};