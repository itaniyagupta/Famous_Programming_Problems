// Problem statemnt link - https://practice.geeksforgeeks.org/problems/factorial5739/1

// Recursive
// Time : O(n^n)

class solution{
		public:
			int factorial(int n)
			{
				if(n==0)
				{
					return 1;
				}
			return n*(factorial(n-1));
			}
};

// Iterative
// Time : O(n^n)

class solution{
		public:
			int factorial(int n)
			{
				int factorial = 1;
				for(int i=1; i<=n; i++)
				{
					factorial = factorial*i;
				}
			return factorial;
			}
};

// Dyanamic Programming
// Time: O(n)

class solution{
		public:
			int Factorial(int n)
            {
			int[] memo = new int[n + 1];
			memo[0] = 1;

			for(int i=1;i<=n;i++)
			{
				memo[i] = i * memo[i-1];
			}
			return memo[n];
    }
};