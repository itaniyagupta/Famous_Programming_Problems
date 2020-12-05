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
 
// Recursive
// Time : O(n)
 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
     
        int rootData= preorder[0];
        TreeNode* root = new TreeNode(rootData);
        for(int i=1; i<preorder.size(); i++)
        {
            root=constructBST(root,preorder[i]);
        }
      return root;  
     }
     TreeNode* constructBST(TreeNode* root,int val){
            if(root==NULL)
            {

                return new TreeNode(val);
            }
            if(val < root-> val)
            {
                root->left=constructBST(root->left,val); 
            }
            if(val > root-> val)
            {
                 root->right=constructBST(root->right,val);
            }
         return root;
     }
};