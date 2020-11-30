// Brute Force1
// Time : O(n^3)

class solution{
		public:
			int maxlengthsubarray(vector<int>& nums)
			{
				int max_len = 0;
				for(int i=0; i<n-1; i++)
				{
					for(int j=0; j<n-1; j++)
					{
						int sum =0;
						for(int k=i; k<j; k++)
						{
						sum =+ nums[k];
						if(sum == 0)
						{
							if(max_len < j-i+1)
							{
								max_len = j-i+1;
							}
						}
					}
				}
				return max_len;
			}
};
						
// Brute Force2
// Time : O(n^2)

class solution{
		public:
			int maxlengthsubarray(vector<int>& nums)
			{				
				int max_len = 0;
				for(int i=0; i<n-1; i++)
				{
					int sum =0;
					for(int j=0; j<n-1; j++)
					{
						sum =+ nums[k];
						if(sum == 0)
						{
				        	max_len = j-i+1;
							
						}
					}
				}
				return max_len;
			}
};

// Hash Map
// Time : O(n)

class solution{
		public:
			int maxlengthsubarray(vector<int>& nums)
			{
				unorderd_map <int, int> H;
				int sum=0;
				int max_len =0;
				for(int i=0; i<n-1; i++)
				{
					sum =+ nums[k];
					if(sum == 0)
					{
							if(max_len < i)
							{
								max_len = i+1;
							}
					}
					else if(H.find(sum) != H.end())
					{
						if(maxlen < i- H[sum])
						{
							maxlen = i-H[sum];
						}
						else
						{
							H[sum] = i;
						}
					}
				}
				return max_len;
			}
};
				