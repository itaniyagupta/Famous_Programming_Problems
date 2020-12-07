// Time : O(n log( n)); Space : O(1)
// Sorting In-Place : Yes
// Stable : No

class solution{
  public:
  void heapify(vector<int>& arr, int n, int i) {
  
  int largest = i;                  // Initilaizing largest as root
  int left = 2 * i + 1;
  int right = 2 * i + 2;
   
                 // if left child node is larger than the root node
  if (left < n && arr[left] > arr[largest])
  {
    largest = left;
  }
                // if right child node is larger than the root node
  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }
       // if largest is not the root, swap the largest and the root
  if (largest != i) 
  {
    swap(arr[i], arr[largest]);
  }
   heapify(arr, n, largest);
  }
   }
   
  
   void heapSort(vector<int>& arr) {
   int n = arr.size();
                                             // Building the heap
   for (int i = n / 2 - 1; i >= 0; i--)
   {
     heapify(arr, n, i);
   }
    
   for (int i = n - 1; i >= 0; i--) {
     swap(arr[0], arr[i]);
     heapify(arr, i, 0); 
   }
   }
}


