// Problem Statement Link - https://leetcode.com/problems/median-of-two-sorted-arrays/

// Time : O(m+n); Space:O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                 
            int i = 0, j = 0, count;  
            double m1 = 0, m2= 0; 
            
         if((nums1.size() + nums2.size()) % 2 == 1)  
         {  
            for (count = 0; count <= (nums1.size() + nums2.size())/2; count++) 
            {  
                if(i != nums1.size() && j != nums2.size()) 
                {  
                    m1 = (nums1[i] > nums2[j]) ? nums2[j++] : nums1[i++];  
                }  
                else if(i < nums1.size()) 
                {  
                    m1 = nums1[i++];  
                }  
                else
                {  
                    m1 = nums2[j++];  
                }  
            }  
            return m1;  
         }  
        else 
        {  
            for (count = 0; count <= (nums1.size() + nums2.size())/2; count++)  
            {  
                m2 = m1;  
                if(i != nums1.size() && j != nums2.size()) 
                {  
                    m1 = (nums1[i] > nums2[j]) ? nums2[j++] : nums1[i++];  
                }  
                else if(i < nums1.size()) 
                {  
                    m1 = nums1[i++];  
                }  
                else
                {  
                    m1 = nums2[j++];  
                }  
            }  
        return (m1 + m2)/2;  
        }
    
    }
};