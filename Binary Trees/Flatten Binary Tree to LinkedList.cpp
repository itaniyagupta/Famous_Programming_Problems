// Problem statement : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Recursive
// Time : O(n); Space : O(h), where h: height of tree

class Solution {
public:
    void flatten(TreeNode* root) {
            TreeNode* temp = NULL;
            reverse_preorder(root, &temp);
    }
    void reverse_preorder(TreeNode* root, TreeNode** temp) 
    {
        if(root == NULL)
        {
          return;   
        }
        if(root->right != NULL)
        {
          reverse_preorder(root->right, temp);
        }
         if(root->right != NULL)
        {
           reverse_preorder(root->left, temp);
        }
     
        root->right = *temp;
        root->left = NULL;
        *temp = root;
    }
};


// Using stack
// Time: O(n); Space: O(n)

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
        {
             return;
        }
           
        stack<TreeNode*> S;
        S.push(root);
        while(!S.empty())
        {
            TreeNode* root = S.top();
            S.pop();
            if(root->right != NULL)
            {
                 S.push(root->right);
            }
            if(root->left != NULL)
            {
                 S.push(root->left);
            }
            if(!S.empty())
             root->right = S.top();
             root->left = NULL;
        }
    }
};

// Iterative
// Time : O(n); Space : O(1)
class Solution{
    public:
    void flatten(TreeNode* root) 
        {
            TreeNode* temp = root;
            while (temp != NULL)
            {  
                if (temp->left !=NULL)
                {
                    if (temp->right !=NULL)
                    {
                        TreeNode* next = temp->left;
                        while (next->right != NULL)
                        {
                            next = next->right;
                        }
                        next->right = temp->right;
                    }
                    temp->right = temp->left;
                   temp->left = NULL;
                }
              temp = temp->right;
            }
        }
};