// Time : O(n+k);Space : O(k)
// Stable : Yes
// Sorting In-Place : No

class solution{
 public:
  void countSort(vector<int>& arr) {
   
     int size = arr.size();
     vector<int> temp;
     vector<int> output;
                                      // Finding largest element
     int max = arr[0];
     for (int i = 1; i < size; i++) {
    if (arr[i] > max)
      max = arr[i];
     }
                            // Initializing count array with zero
     for (int i = 0; i <= max; ++i) {
    temp[i] = 0;
     }
                             // calculating count of each element
     for (int i = 0; i < size; i++) {
    temp[arr[i]]++;
     }
for (int i = 1; i <= max; i++) {
    temp[i] += temp[i - 1];
     }
                                                      // mapping 
     for (int i = size - 1; i >= 0; i--) 
     {
    output[temp[arr[i]] - 1] = arr[i];
    temp[arr[i]]--;
     }
                   // copying sorted eleemnts to the target array
     for (int i = 0; i < size; i++) {
    arr[i] = output[i];
     }
  }
};