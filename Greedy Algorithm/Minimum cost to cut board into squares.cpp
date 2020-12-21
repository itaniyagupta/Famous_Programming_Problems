

class solution{
	public:
		int minimumCostOfBreaking(vector<int>& X , vector<int>& Y) 
		{ 
			int res = 0; 
			int m = X.size(), n=Y.size();
		  
			sort(X, X + m, greater<int>()); 
			sort(Y, Y + n, greater<int>()); 
		  
			int horizontal = 1, vertical = 1; 
		  
			int i = 0, j = 0; 
			while (i < m && j < n) 
			{ 
				if (X[i] > Y[j]) 
				{ 
					res += X[i] * vertical; 
					horizontal ++; 
					i++; 
				} 
				else
				{ 
					res += Y[j] * horizontal ;
					vertical++; 
					j++; 
				} 
			} 
		  
			int total = 0; 
			while (i < m) 
				total += X[i++]; 
			res += total * vertical; 
		  
			total = 0; 
			while (j < n) 
				total += Y[j++]; 
			res += total * horizontal; 
		  
			return res; 
		} 
};