// Problem Statement Link - https://practice.geeksforgeeks.org/problems/common-elements1132/1

// Time: O(n1+n2+n3); Space O(1)

class solution{
		public:
			void findcommon(vector<int>& nums1,vector<int>& nums2, vector<int>& nums3)
			{
				int n1 = nums1.size();
				int n2 = nums2.size();
				int n3 = nums3.size();
				
				int i=0; j=0; k=0;
				
				while(i<n1 && j<n2 && k<n3)
				{
					if(nums1[i] = nums2[j] && nums2[j] == nums3[k])
					{
						int x= nums1[i];
						i++;
						j++;
						k++;
					}
					else if(nums1[i] < nums2[j])
					{
						i++;
					}
					else if(nums2[j] < nums3[k])
					{
						j++;
					}
					else
					{
						k++;
					}
				}
			}
};
