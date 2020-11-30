// Problem Statement Link - https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0

class solution{
		public:
			int factorial(int n)
			{
				vector<int> res;
				res[0] = 1;
				int res_size  =1;
				for(int x=2; x <=n; x++)
				{
					res_size = multiply(x, res, res_size);
				}
				return res[i];
			}
			
			int multiply(int x, vector<int> res, int res_size)
			{
				int carry = 0;
				for(int i=0; i< res_size; i++)
				{
					int prod = res[i] * x + carry;
					res[i] = prod%10;
					carry = prod/10;
				}
				while(carry)
				{
					res[res_size] = carry%10;
					carry = carry/10;
					res_size++;
				}
				return res_size;
			}
};
