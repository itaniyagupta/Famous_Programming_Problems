// Time : O(nlogn); Space : O(n)
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
   int mid = (low + high)/ 2; // getting the mid point
   mergesort(arr,low, mid); // sorting the left half
   mergesort(arr, mid+l, high); // sorting right half
   merge(arr, low, mid, high); //merging
  }
 }
                                  // function to merge two subarrays
 void merge(vector<int>& arr, int low, int mid, int high) {
  
  vector<int> helper;
                // copying elements from both halves to helper array
  for (int i= low; i <= high; i++) {
   helper[i] = arr[i];
   }
int Left = low; 
  int Right = mid + l;
  int curr = low;
   // comparing and then copying smaller element back to input array
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
                        // copying remaining elements to final array
  int rem = mid - left;
   for (int i= 0; i <= rem; i++) 
   {
   arr[curr + i] = helper[left + i];
   }
  }
};