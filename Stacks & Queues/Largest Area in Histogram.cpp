// Problem Statement Link - https://leetcode.com/problems/largest-rectangle-in-histogram/


// Brute force
// Time : O(n^2), Space : O(1) 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        for(int i=0; i<heights.size(); ++i) 
        {
            int height = heights[i];
            for(int j=i; j < heights.size(); ++j)
            {
                height = min(height, heights[j]);
                maxArea = max(maxArea, height*(j-i+1));
            }
        }
        return maxArea; 
    }
};

// Using Stack
// Time : O(n), Space : O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int height = 0;
        int area = 0;
        stack<int> st;
        st.push(-1); 
        for(int i=0; i<heights.size(); ++i)
        {
            while(st.top() != -1 && !(heights[i] > heights[st.top()])) 
            {
                height = heights[st.top()];
                st.pop();
                area = height*(i-st.top()-1);
                maxArea = (maxArea > area ) ? maxArea : area ;
            }
            st.push(i);
        }
        while(st.top() != -1) 
        {
            height = heights[st.top()];
            st.pop();
            area = height*(heights.size()-st.top()-1);
            maxArea = maxArea > area ? maxArea : area;
        }
        return maxArea;
    }
};