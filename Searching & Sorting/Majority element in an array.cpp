//Problem statement link - 

// Brute Force
// Time : O(n^2); Space : O(1)
class solution{
 public:
	int findMajorityElement(vector<int> arr)
	{
		for (int i = 0; i< arr.size()-2; i++)
		{
			int count = 1
			for (int j = i+1; j<arr.size()-1; j++)
			{
				if (arr[i] == arr[j])
					count++;
			}
		    if ( count > arr.size()/2 )
				return arr[i];
		}
		return -1
	}
};

// Using sorting
// Time : O(n logn); Space : O(n)

class solution{
 public:
	int findMajorityElement(vector<int> arr){
		sort(arr.begin(), arr.end());
		int i = 1;
		int count = 1;
		while ( i < arr.size())
		{
			while ( i < arr.size() && arr[i] == arr[i-1] )
			{
				i++;
				count++;
			}
		   if (count > arr.size()/2 )
				return arr[i-1];
			
			count = 1;
			i++;
		}
		return -1;
	}
};

// Using Hash Table
// Time : O(n); Space: O(n)

class solution{
 public:
	int findMajorityElement(vector<int>& arr)
	{
		unordered_map<int,int> hash;
		for (int i = 0; i<arr.size()-1; i++)
		{
			if (hash.find(arr[i]) != hash.end())
			{
			   hash[arr[i]] = hash[arr[i]] + 1;
			}
			else
			{
				hash[arr[i]] = 1;
			}
			if (hash[arr[i]] > arr.size()/2)
				return arr[i];
		}
		return -1;
	}
};

// Boyer-Moor majority vote algorithm
// Time : O(n); Space: O(1)

class solution{
 public:
	int findMajorityElement(vector<int>& arr)
    {
		int max_index = 0;
		int count = 0;
		for(int i = 0; i< arr.size()-1; i++)
		{
			if ( arr[i] == arr[max_index] )
				count++;
			else
				count--;
			
			if (count == 0)
			{
				max_index = i;
				count = 1;
			}
		}
		count = 0;
		for (int i = 0; i< arr.size()-1; i++)
		{
			if (arr[i] == arr[max_index])
				count++;
		}
		
		if (count > arr.size()/2)
			return arr[max_index];
		else
			return -1;
    }
};