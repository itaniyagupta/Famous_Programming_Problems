// problem statement link - https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
 
 // Iterative
 // Time : O(n); Space: O(n)
 
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
     
         
        vector<double> res;
        
          if(root == NULL){
            return res;
        }
        
        queue<TreeNode*> temp;
        temp.push(root);
        
         double sum= 0;
        
        while(temp.size() != 0)
        {
              int count=0;
            vector<int> res1;
             int s =temp.size();
               int k=s;
            for(int i=0;i<s;i++)
            {
                TreeNode* front = temp.front();
                res1.push_back(front->val);
                temp.pop();
                
                sum+=(double)front->val;
                
                if(front->left!=NULL){
                    count++;
                    temp.push(front->left);
                }
                if(front->right!=NULL){
                    count++;
                    temp.push(front->right);
                }
            }
            
            res.push_back((double)sum/k);
            sum = 0;
        }
        return res;
    }
};

