// Problem statement : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
      7   <- level 0               7
	/  \							\
   6    5  <- level 1          => 	 5	
  /	\  / \							  \
 2  1 3   4 <- level 2				   6
										\
										 2
										  \
										   1
										    \
											 3
											  \
											   4
 Zig ZagLevel order traversal : 7 5 6 2 1 3 4
 
 Input : [7,6,5,2,1,3,4]
 Output :[7,null,6,null,2,null,1,null,5,null,3,null,4]
*/


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
        {  // if root is null return
          return;   
        }
        if(root->right != NULL)
        {
          reverse_preorder(root->right, temp);  // process right sub-tree
        }
         if(root->left != NULL)
        {
           reverse_preorder(root->left, temp);  // process left sub-tree
   
        }
     
        root->right = *temp; // set the right child of root with the left flattened tree
        root->left = NULL; // left of root is marked null
        *temp = root;    // set the temp variable with the current node
    }
};


// Using stack
// Time: O(n); Space: O(n)

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
        {  // if root is empty, return
             return;
        }
           
        stack<TreeNode*> S; // stack to store vales of tree nodes
        S.push(root);	// push root onto stack
        while(!S.empty()) // traverse till stack is not empty
        {
            TreeNode* root = S.top();  // store top value of stack into root
            S.pop();
            if(root->right != NULL)   // if right of root exists, push it into stack
            {
                 S.push(root->right);
            }
            if(root->left != NULL) // if left of root exists, push it into stack
            {
                 S.push(root->left);
            }
            if(!S.empty())  // till the stack is not empty
             root->right = S.top();  //root right points to top value of stack
             root->left = NULL; // left is marked null
        }
    }
};

// Iterative
// Time : O(n); Space : O(1)
class Solution{
    public:
    void flatten(TreeNode* root) 
        {
            TreeNode* temp = root;  // storing root into temp of type TreeNode*
            while (temp != NULL)  // Traverse till the temp is not null
            {  
                if (temp->left !=NULL) // Traverse till left side of temp is not null
                {
                    if (temp->right !=NULL)  // Traverse till right side of temp is not null
                    {
                        TreeNode* next = temp->left; // storing left of temp in next of type treenode*
                        while (next->right != NULL) // Traverse till right side of next is not null
                        {
                            next = next->right; // next points to right of next
                        }
                        next->right = temp->right; // right of next point to right of temp
                    }
                    temp->right = temp->left;   // right of temp point to left of temp
                   temp->left = NULL;  // left of temp is marked null
                }
              temp = temp->right; //temp points to right of temp 
            }
        }
};

