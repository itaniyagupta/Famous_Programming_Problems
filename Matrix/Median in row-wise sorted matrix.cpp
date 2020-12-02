// Problem Statement Link - https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// Brute Force
// Time:  O(N*M*log(N*M); Space :  O(N*M)

class solution{
	public:
	int medianRowwiseSortedMatrix(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
        int n =matrix[0].size(); 
		vector<int> temp(n*m);
		
		int desired_index = (1+n*m)/2 -1;
	    int index = 0 ;   
		for(int i=0; i<m; i++)
		{
		  for(int j=0; j<n; j++)
		  {
			 tempArr[index++] = matrix[i][j];
		  }
		}
		sort(temp.begin(), temp.end());
		return temp[desired_index];
	}
};

// Binary Search
// Time : O(n*log(m)); Space : O(1)

class solution{
	public:
	int medianRowwiseSortedMatrix(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
        int n = matrix[0].size(); 
		int min = INT_MAX;
		int max = INT_MIN;
		int desired_count = (1+(n*m)/2))
		for(int i=0;i<m;i++)
		{
			if(A[i][0]<min)
			{	
			 min = A[i][0];
			}
			if(A[i][n-1]>max)
			{
			max = A[i][n-1];
			}
		}
		int counter =0;
		while(min<max)
		{
			counter=0;
			int mid = (max+min)/2;
			for(int i= 0;i<n;i++)
			{
				counter += upper_bound(A[i], A[i]+m, mid) -  A[i];
			}
			if(counter < desired_count)
				min = mid+1;
			else
				max = mid;
		}
		return min;
	}
};