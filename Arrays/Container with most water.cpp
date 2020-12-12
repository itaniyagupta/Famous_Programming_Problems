https://leetcode.com/problems/container-with-most-water/

// Time : O(n^2); Space : O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {  
        
        int n= height.size();
        int maxarea = 0;
        for(int i = 0; i< n; i++)
        {
            for(int j = i; j < n; j++)
            {
                int minheight = min(height[j], height[i]);
                int area = (j - i)*minheight;
                maxarea = max(maxarea,area);
            }
        }
        return maxarea;   
    }
};


// Time : O(n); Space : O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {  
        if (height.empty()) {
            return 0;
        }
        
        int maxarea=0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            
            int minHeight = min(height[left], height[right]);
            int area = (right - left)*minHeight;
            maxarea = max(maxarea, area);
            if (height[left] < height[right]) 
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxarea;
    }
};