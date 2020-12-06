class solution{
public:
	void bucketSort(vector<float> arr) 
	{  
		int n = arr.size();
		vector<float> bucket; 
	
		for (int i = 0; i < n; i++) 
		{ 
			int index = n * arr[i]; 
			bucket[index].push_back(arr[i]); 
		} 
	  
		for (int i = 0; i < n; i++) 
		{
			sort(bucket[index].begin(), bucket[index].end()); 
		}
	  
	    int k = 0;                        
		for (int i = 0; i < n; i++)
        { 		
			for (int j = 0; j < b[i].size(); j++)
            {			                                     // Concatenating all buckets into arr[] 
				arr[k++] = bucket[i][j]; 
			}
	    }
	} 
};