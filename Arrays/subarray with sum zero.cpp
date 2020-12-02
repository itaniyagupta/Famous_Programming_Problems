// Problem statemnt link - https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0

class solution{
		public:
			bool subarray exist(vector<int>& nums)
			{
				unordered_set<int> sumset;
				
				int sum =0;
				for(int i=0; i<n; i++)
				{
					sum += nums[i];
					
					if(sum ==0 || sumset.find(sumset.find(sum) != sumset.end())
					{
					return true;
					}
					sumset.insert(sum);
				}
				return false;
			}
};