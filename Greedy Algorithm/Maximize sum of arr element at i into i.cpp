
class solution{
	public:
	int maxSum(vector<int>& arr, int n) 
    {   
	  sort(arr.begin(), arr.end()); 
	  int sum = 0; 
	  for (int i = 0; i < n; i++) 
	  {
		sum += (arr[i]*i); 
	  }
	  return sum; 
	}
};