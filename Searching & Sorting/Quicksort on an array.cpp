//  Runtime: O(n log( n)) in best/average, O(n^2) in worst case; Space: 0(log(n))
// Sorting In Place: Yes
// Stable: No


class solution{
 public:
 void quicksort(vector<int>& arr){
  int start =0;
  int end = arr.size()-1;
  int index = partition(arr, start, end);
  if (start< index - 1) 
  {
     quicksort(arr, start, index - 1);
  }
  if (index< end) 
  {
     quicksort(arr, index, end);
  } 
 }
int partition (vector<int>& arr, int start, int end){
  int pivot = arr[(start + end)/2];  
                                          // Picking the pivot point
  while (start <= end) 
  {    
       // Finding element on left side which should be on right side
   while (arr[start] < pivot) 
   {
    start++; 
   }   
       // Finding element on left side which should be on right side
   
   while (arr[end] > pivot) 
   {
    end--; 
   }
   if (start<= end) 
   {            // swapping elements and moving start & end indexes
    swap(arr, start, end); 
    start++;
    end--; 
   }
  }
  return start;
 }
};