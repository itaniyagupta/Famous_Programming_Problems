// Problem Statement Link - https://leetcode.com/problems/merge-sorted-array/

// Time : O(nlogn); Space: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      
        int i=0;
        for(int j=m; j<n+m; j++)
        {
           nums1[j]=nums2[i];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};

//Using merge fn of merge sort 
// Time : O(m+n); Space: O(m+n)
class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int i=0; j=0; k=0;
		
		vector<int> nums3;
		
		while(i<m && j<n){
			if(nums1[i] < nums2[j]){
				nums3[k] = nums1[i];
				i++;
			}
			else{
				nums3[k] = nums2[j];
				j++;
			}
			k++;
		}
		while(i<n){
			nums3[k] = nums1[i];
			i++;
			k++;
		}
		while(j<n){
			nums3[k] = nums2[j];
			j++;
			k++;
		}
		i=0;
		while(i<(m+n)){
			nums1[i] = nums3[i];
			i++;
		}
		return nums1;
	}
};

// Using two pointers approach
// Time : O(m+n); Space : O(1)

class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2) {

		int m = nums1.size();
		int n = nums2.size();
		int i=m-1; j=n-1; k=m+n-1;
		
		while(i>=0 && j>=0){
			if(nums1[i] < nums2[j]){
				nums1[k] = nums1[i];
				i--;
			}
			else{
				nums1[k] = nums2[j];
				j--;
			}
			k--;
		}
		while(i>=0){
			nums1[k] = nums1[i];
			i--;
			k--;
		}
		while(j>=0){
			nums1[k] = nums2[j];
			j--;
			k--;
		}
		return nums1;
	}
};
		 
		
			
			