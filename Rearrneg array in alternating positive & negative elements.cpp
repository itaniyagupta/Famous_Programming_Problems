// Problem Statement Link - https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

// Time: O(n); Space O(1)

class solution{
		public:
			void rearrange(vector<int>& nums)
			{
				int n = nums.size();
				int i=1;
				for(int j=0; j<n; j++)
				{
					if(nums[j] < 0)
					{
						i++;
						swap(nums[i], nums[j]);
					}
				}
				int pos = i+1, neg =0;
				while(pos<n && neg < pos &&nums[neg] <0)
				{
					swap(nums[neg], nums[pos]);
					pos++;
					neg+=2;
				}
			}
};