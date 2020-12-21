

// Time :O(nlogn)

int findMinimum(vector<int>& arr, int k)
{
	int n = arr.size();
	sort(arr.begin(), arr.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
      
        res += arr[i];
        n = n - k;
    }
    return res;
}
 
int findMaximum(vector<int>& arr, int k)
{
	int n=arr.size();
	sort(arr.begin(), arr.end());
    int res = 0, index = 0;
 
    for (int i = n - 1; i >= index; i--) 
    {
     
        res += arr[i];
        index += k;
    }
    return res;
}