// Problem Statement Link - https://leetcode.com/problems/intersection-of-two-arrays
// Time : O(m+n); Space: O(min(m,n))

class solution{
		public:
			 vector<int> Intersection(vector<int>& nums1, vector<int>& nums2){
			
				vector<int> nums3;
                int i=0,j=0;
				while(i<nums1.size()&&j<nums2.size())
				{
					if(nums1[i]<nums2[j])
					{
						i++;
					}
					else if(nums1[i]>nums2[j])
					{
						j++;
					}
					else
					{
						bool can=true;
					 for(int x:nums3)
						 if(x==nums1[i])
						 {can=false;
						  break;}
					 if(can)
						nums3.push_back(nums1[i]);
					 i++;
					 j++;
					}
				}
				return nums3;
			}
};