// Time : O(n) ; Space : O(1)

class solution {
public:	
	void reverse array(vector<int>& nums) {
	  
	   int start =0;
	   int end = nums.size()-1;
	   
	   while(start < end)
	   {
		swap(nums[start++], nums[end--]);

	   }
	}
};
	
	/* Swap works as 
	  
	  int temp = nums[start];
	  nums[start] = nums[end];
	  nums[end] = temp;
	  start++;
	  end--;
	  
	*/
