// Problem statement Link- https://leetcode.com/problems/rotate-image/

// Transpose & Reverse
// Time: O(n^2); Space: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();i++)
        {
			for(int j=i;j<matrix.size();j++)
			{
					swap(matrix[i][j],matrix[j][i]);
			}
		}
        for(int i=0;i<matrix.size();i++)
        {
           reverse(matrix[i].begin(),matrix[i].end());
        }       
    }
};

// Inplace rotation
// Time: O(n^2); Space: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		
		int n = matrix.size();
		int layer  = 0;
		while(layer < n/2){ 
			int low = layer;
			int high = n- 1 - layer;
			for (int i = low; i<high; i++)
			{
				int temp = matrix[low][i];
				matrix[low][i] = matrix[N-1-i][low];
				matrix[N-1-i][low] = matrix[N-1-low][N-1-i]; 
				matrix[N-1-low][N-1-i] = matrix[i][N-1-low];
				matrix[i][N-1-low] = temp;
			}
			layer++;
		}
	}
};
