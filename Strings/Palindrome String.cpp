//Problem statement link - https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

class solution{
	public:
		bool isPalindrome(string str) 
		{ 
			// Start from leftmost and rightmost corners of str 
			int l = 0; 
			int h = str.size()- 1; 
		  
			while (h > l) 
			{ 
				if (str[l++] != str[h--]) 
				{ 
					return false; 
				} 
			} 
			return true;
		} 
};