// Problem Statement Link - https://leetcode.com/problems/recover-binary-search-tree/

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

// Time : O(logn); Space : O(n)

class Solution {
public:
    int i=0;
    void inorder(TreeNode* root, vector<int>& List)
    {
         if(root == NULL)
           return;
        inorder(root->left, List);
         List.push_back(root->val);
        inorder(root->right, List);
    }
    void correct(TreeNode* root,  vector<int>& List)
    {
        if(root == NULL)
           return;
        correct(root->left, List);
        root->val=List[i++];
        correct(root->right, List);
    }
      
    void recoverTree(TreeNode* root) 
    { 
        vector<int>List; 
        inorder(root, List);
        sort(List.begin(), List.end());
        correct(root, List);
    }
};

// Time : O(n); Space : O(1)

class Solution {
public:
        void helper(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second)
        {
            if(root == NULL) return ;
            helper(root->left, prev, first, second);
            if(prev && prev->val>root->val)
            {
                if(first == NULL) 
                first = prev;
                second = root;
            }
            prev = root;
            helper(root->right, prev, first, second);
        }
     void recoverTree(TreeNode* root) 
        {
        TreeNode *first = NULL, *second = NULL, *prev = NULL;
        helper(root, prev, first, second);
        if(first != NULL) swap(first->val, second->val);
        }
};