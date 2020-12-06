// Time : O(logn); Space : 0(n)
// Sorting In Place: No
// Stable: Yes

class solution{
	public:

	void mergesort(vector<int>& arr) {
	    int n= arr.size();
		mergesort(arr, 0, n-1);
	}

	void mergesort(vector<int>& arr, int low, int high) {
		if (low< high) 
		{
			int mid = (low + high)/ 2;
			mergesort(arr,low, mid); 
			mergesort(arr, mid+l, high); 
			merge(arr, low, mid, high); 
		}
	}

	void merge(vector<int>& arr, int low, int mid, int high) {
		
		vector<int> helper;
		for (int i= low; i <= high; i++) {
		 helper[i] = arr[i];
		 }

		int Left = low; 
		int Right = mid + l;
		int curr = low;

		while (Left <= mid && Right <= high) 
		{
		 if (helper[left] <= helper[Right]) 
		 {
		   arr[curr] = helper[left];
		   helperleft++;
		 } 
		 else 
		 {
		   arr[curr] = helper[Right];
		   Right++;
		 }
		 curr++;
		 }
		
		int rem = mid - left;
		 for (int i= 0; i <= rem; i++) 
		 {
		 arr[curr + i] = helper[left + i];
		 }
	 }
};