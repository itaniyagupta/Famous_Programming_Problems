
class solution{
  public:
	bool survival(int S, int N, int M) 
	{ 
	  
		if (((N * 6) < (M * 7) && S > 6) || M > N) 
		{
				return false;
		}
		else 
		{ 
		   
			int days = (M * S) / N; 
			if (((M * S) % N) != 0)
			{		
				days++; 
			}
			return true;
		} 
	}
};