// Problem statement - Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures? 

// Follow up question:  if string is an ASCII string or a Unicode string

// following code is for ASCII; incase of extended ASCII increase size to 256

// Fisrt two approaches are using additional data structures
// Time : O(n); Space  : O(1)
class solution{
 public:
	bool isUniqueChars(String str) {
			
		if (str.length() > 128) 
			return false;
			
		vector<bool> char_set(128);
		for (int i= 0; i < str.length(); i++) 
		{
			int val= str.charAt(i);
		    if (char_set[val]) 
			 {	
				return false;
			 }
		    char_set[val] = true;
		}
	return true;
    }
};

class solution{
 public:
	bool isUniqueChars(String str) {
		int checker= 0;
		for (int i= 0; i < str.length(); i++) 
		{
			 int val= str.charAt(i) - 'a';          // iterating over string,finding int value of the character w.r.t ‘a’
			 if ((checker & (1 << val)) > 0)                      // bit at that int value is set to 1
			 {
			  return false;          // if this bit is already set in the checker, the bit AND operation would make checker > 0. retrun false
			 }
			 checker I= (1 << val); //Else Update checker to make the bit 1 at that index
		}
	 return true;
   }
};

// No additional data structure is allowed following two approaches

// Time : O(n^2)

class solution{
 public:
	bool uniqueCharacters(string str)
	{
		for (int i = 0; i < str.length() - 1; i++) 
		{
			for (int j = i + 1; j < str.length(); j++) 
			{
				if (str[i] == str[j]) 
				{
					return false;
				}
			}
		}
		return true;
	}
};

// sorting
// time : O(nlogn)
	
class solution{
	public:
		bool uniqueCharacters(string str)
		{
		 
			sort(str.begin(), str.end());
		 
			for (int i = 0; i < str.length()-1; i++) {
		
				if (str[i] == str[i + 1]) 
				{
					return false;
				}
			}
			return true;
		}
};