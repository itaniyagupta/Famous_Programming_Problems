// Time : O(n^2) -in worst case O(n) in Best case; Space: O(1)
// Sorting In Place: Yes
// Stable: Yes

class solution{
  public:
 void insertionSort(vector<int>& arr[])  
 {  
  int n = arr.size();
  for (int i = 1; i< n-1; i++) 
  {  
   int key = arr[i];
   int j = i - 1; 
             // moving elements greater than key to one index ahead
   while (j >= 0 && arr[j] > key)
   {  
    arr[j + 1] = arr[j];
    j--;
   }  
   arr[j + 1] = key; 
  }  
 } 
};

// Recursive Insertion Sort
// Time : O(n^2); Space : O(n)

class solution{
  public:
	void recursive_insertion_sort(vector<int>& arr[]) { 
		
		int n = arr.size();
		if (n <= 1) 
			return;
		
		recursive_insertion_sort( arr, n-1 );
		int val = arr[n-1];
		int pos = n-2;
		while (pos >= 0 && arr[pos] > val) 
		{ 
			arr[pos+1] = arr[pos];
			pos--;
		} 
		arr[pos+1] = val;
	}
};