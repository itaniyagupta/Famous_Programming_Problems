// Time Complexity : O(n+k) in Best & Average case & O(n²) in worst case.
// Space Complexity : O(n)
// Sorting In-Place : No

class solution{
public:
 void bucketSort(vector<float> arr) 
{  
  int n = arr.size();
  vector<float> bucket; 
                              // Pushing the elements into buckets
  for (int i = 0; i < n; i++) 
  { 
   int index = n * arr[i]; 
   bucket[index].push_back(arr[i]); 
  } 
                               // sorting elements of each bucket
  for (int i = 0; i < n; i++) 
  {
   sort(bucket[index].begin(), bucket[index].end()); 
  }
   
     int k = 0;                        
   for (int i = 0; i < n; i++)
        {   
     for (int j = 0; j < b[i].size(); j++)
            {               // Concatenating all buckets into arr 
    arr[k++] = bucket[i][j]; 
            }
        }
 } 
};