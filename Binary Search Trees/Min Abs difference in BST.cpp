
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
  public:
	void inorder(TreeNode* root, vector<int>& arr){
        if(root == NULL)
            return;
        inorder(root->left, arr);
        arr.push_back(root->val);            
        inorder(root->right, arr);
		}
		
    int getMinimumAbsDiff(TreeNode* root) {
        vector<int> arr;
        int min_so_far = INT_MAX; 
        inorder(root, arr);
        for(int i=0; i<arr.size(); i++)
        {
            if ((arr[i+1] - arr[i]) < min_so_far)
			{
                min_so_far = arr[i+1] - arr[i]; 
			}
        }
        return min_so_far;
    }
};