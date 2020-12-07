// Linear Search
// Time : O(n); Space : O(1)

class solution {
	public :
		int search_infiniteArray(vector<int>& arr, int K)
		{
			int i = 0;
			while (arr[i] <= K)
			{
				if(arr[i] == K)
					return i;
				else
					i++;
			}
		   return -1;
		}
};
