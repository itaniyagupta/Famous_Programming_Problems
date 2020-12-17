// Problem statement - https://leetcode.com/problems/valid-anagram/

/* Follow up question:  if string is an ASCII string or a Unicode string
						Permutation comparison is case sensitive or not?
						whitespace is significant or not?
*/

class solution{
	public:

    bool permutation(String s, String t) { 
		
		if (s.size() != t.size()) 
		  return false; 
	  
		sort(s.begin(), s.end()); 
		sort(t.begin(), t.end()); 
	  
		for (int i = 0; i < s.size();  i++) 
		{
		   if (s[i] != t[i]) 
		   {
			 return false; 
		   }
		}
	 return true; 
	}
};


class solution{
	public:
		bool permutation(String s, String t) {
		  if (s.length() != t.length()) 
		  {
			return false;
		  }
		}
		vector<int> letters(128); 
		vector<char> s_array = s.toCharArray();
		for (char c : s_array) 
		{
		   letters[c]++;
		}
		for (int i= 0; i < t.length(); i++) 
		{
		   int c = (int) t.charAt(i);
		   letters[c]--;
		   if (letters[c] < 0) 
		   {
			return false;
		   }
		}
		return true;
};