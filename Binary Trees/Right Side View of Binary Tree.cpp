// Problem statemnt Link - https://leetcode.com/problems/binary-tree-right-side-view/submissions/

class Solution {
public:
    
    vector<int> res;
    void rightView(TreeNode* root, int level, int *max_level){ 
            if (root==NULL) 
            {
                return; 
            }
        
            if (*max_level < level) 
            { 
                res.push_back(root->val);
                *max_level = level; 
            } 
 
            rightView(root->right, level+1, max_level); 
            rightView(root->left, level+1, max_level); 
       }
    
    vector<int> rightSideView(TreeNode* root) {
     
        int max_level = 0; 
        rightView(root, 1, &max_level); 
        return res;
    }
};


