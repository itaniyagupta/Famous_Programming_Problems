// Time : O(kn) ; Space : O(n+k)
// Stable : Yes
// Sorting In-Place : No
class solution{
 public:
      void countSort(vector<int>& arr, int index) {
   
        const int max = 10;         // creating groups of size 0-9
     int size = arr.size();
     vector<int> output;
     vector<int>temp;
for (int i = 0; i <= max; ++i) {
    temp[i] = 0;
     }
                           // Calculating occurences of each element
     for (int i = 0; i < size; i++) {
    temp[(arr[i]/index)%10]++;
     }
for (int i = 1; i <= max; i++) {
    temp[i] += temp[i - 1];
     }
                                // Placing elements in sorted order
     for (int i = size - 1; i >= 0; i--) 
     {
    output[temp[(arr[i]/index)%10] - 1] = arr[i];
    temp[(arr[i]/index)%10]--;
     }
for (int i = 0; i < size; i++) {
    arr[i] = output[i];
     }
  }
void radixsort(vector<int>& arr) {
   int size = arr.size();
                                   // finding the maximum element
   int maxelem = arr[0];
   for (int i = 1; i < size; i++) {
   if (arr[i] > maxelem)
   maxelem = arr[i];
   }
                                        // applying counting sort
   for (int i = 1; maxelem / i > 0; i *= 10)
  countingSort(arr, i);
 }
};