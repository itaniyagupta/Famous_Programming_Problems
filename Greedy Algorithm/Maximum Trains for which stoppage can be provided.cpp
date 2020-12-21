
class Solution {
public:
	int maxStop(vector<vector<int>>& arr, int n, int m) //  n = no. of platforms; m = no. of trains;
	{ 
		vector<pair<int, int> > vect[n + 1]; 
	   
		for (int i = 0; i < m; i++) 
			vect[arr[i][2]].push_back(make_pair(arr[i][1], arr[i][0])); 
	  
		for (int i = 0; i <= n; i++) 
			sort(vect[i].begin(), vect[i].end()); 
		  
		int count = 0; 
		for (int i = 0; i <= n; i++) 
		{ 
			if (vect[i].size() == 0) 
				continue; 
	 
			int x = 0; 
			count++; 
			for (int j = 1; j < vect[i].size(); j++)
			{ 
				if (vect[i][j].second >= vect[i][x].first) 
				{ 
					x = j; 
					count++; 
				} 
			} 
		} 
		return count; 
	} 
};
 