// Time : O(n^2); Space : O(1)
// Sorting In Place: Yes
// Stable: No

class solution{
 public:
	void selectionSort(vector<int>arr)
	{
		int n = arr.size();
		for(int i = 0; i < n-1; i++)
		{
			int minIndex = i;
			for(int j = i; j < n-1;j++)
			{
				if(arr[j] < arr[minIndex])
				  minIndex = j;
			}
			swap(arr[minIndex], arr[i]);
		}
	}
};