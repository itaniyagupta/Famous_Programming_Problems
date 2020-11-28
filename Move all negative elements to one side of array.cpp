// Partition Process of Quicksort
// Time : O(n); Space : O(1)

class solution{
		public:
			void arrange(vector<int>& nums){
				int j=0;
				for(int i=0; i<n; i++){
					if(nums[i]<0){
						if(i!=j){
							swap(arr[i], arr[j];
							j++:
						}
					}
				}
			}
			
			
};

// Two Pointer Approach
// Time : O(n); Space : O(n)

class solution{
		public:
			void arrange(vector<int>& nums){
				
				int left =0;
				int right = nums.size();
				while(left<=right)
				{
					if(nums[left] < 0 && nums[right]<0)
					{
						left +=1;
					}
					else if(nums[left] > 0 && nums[right] < 0)
					{
						swap(nums[left], nums[right]);
						left++;
						right--;
					}
					else if(nums[left] > 0 && nums[right] > 0)
					{
						right--;
					}
					else
					{
						left++;
						right--;
					}
				}
			}
};

// Using another array 
// Time : O(n); Space : O(n)

class solution{
		public:
			void arrange(vector<int>& nums){
				int n = nums.size();
				int temp[n];
				
				int j=0;
				for(int i=0; i<n; i++)
				{
					if(nums[i]>=0)
					{
						temp[j++] = nums[i];
					}
				}
				if(j==n || j==0)
					return;
				
				for(int i=0; i<n; i++)
				{
					if(nums[i] < 0)
					{
						temp[j++] = nums[i];
					}
				}
				memcpy(nums, temp, sizeof(temp));
			}
};
