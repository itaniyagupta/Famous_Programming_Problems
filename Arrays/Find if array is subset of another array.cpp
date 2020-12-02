// Brute Force
// Time :  O(m*n)  

// m is nums1.size(); n = nums2.size()

class solution{
  public:
	bool isSubset(vector<int>& nums1, vector<int>& nums2){

			int j;
			for (int i = 0; i < nums1.size(); i++) 
			{ 
				for (j = 0; j < nums2.size(); j++) { 
					
					if (nums2[i] == nums1[j]) 
						break; 
				} 
				if (int j == nums2.size() ) 
					return false; 
			} 
			return true; 
		} 
};

// Sort + merge
// Time : O(mlogm + nlogn)

class solution{
  public:
		bool isSubset(vector<int>& nums1, vector<int>& nums2){ 
			if (nums1.size() < nums2size()) 
				return 0; 
		  
			sort(nums1.begin(), nums1.end()); 
			sort(nums2.begin(), nums2.end());

			int i = 0, j = 0; 			
		  
			while (i < nums1.size() && j < nums2.size())  
			{ 
				if (nums1[i] < nums2[j]) 
				{
					i++;
				}					
				else if (nums1[i] == nums2[j])  
				{ 
					j++; 
					i++; 
				} 
				else if (nums1[i] > nums2[j]) 
					return 0; 
			} 	  
			if(i < nums2.size()
			{
				return false; 
			}
			else
			{
			   return true;
			}
		}; 
}

// Using Hashset
// Time : O(n)

class solution{
  public:	
	bool isSubset(vector<int>& nums1, vector<int>& nums2){
	 
		set<int> hashset; 
		for (int i = 0; i < nums1.size(); i++) 
		{ 
			hashset.insert(nums1[i]); 
		} 
	 
		for (int i = 0; i < nums2.size(); i++) { 
			if (hashset.find(nums2[i]) == hashset.end()) 
				return false; 
		} 
		return true; 
	}
};


// Using Hashmap
// Time : O(n)

class solution{
  public:
		bool isSubset (vector<int>& nums1, vector<int>& nums2){
		{ 
			map<int, int> count; 
			for (int i = 0; i < nums1.size(); i++) 
			{ 
				count[nums[i]]++; 
			} 
	
			for (int i = 0; i < nums2.size(); i++)  
			{ 
				if (count[nums2[i]] > 0) 
				{
					count[nums2[i]]--; 
				}
				else 
				{ 
					return false; 
				} 
			} 
			return true; 
		} 
};