// Problem Statement Link - https://leetcode.com/problems/binary-tree-inorder-traversal/

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

 /*
 Inorder traversal : Left,  Root, Right
 
     7   
	/ \
   6   5  
  /	\  / \
 2  1 3   4 
 
 Inorder traversal : 2 6 1 7 3 5 4 
 
 Input : [7,6,5,2,1,3,4]
 Output : [2, 6, 1, 7, 3, 5, 4]

*/
 
 // Recursive 
 
class Solution {
public:
// recursive function to traverse the tree
    void inord1(TreeNode* root,vector<int>&res)
    {
        if(root == NULL){ // if root is null return
        return;
        }
          
          inord1(root->left, res);   // recursive calling left subtree
          res.push_back(root->val);  // push root value then
          inord1(root->right, res);  // recursive calling right subtree
         
    }
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;  // vector to store final pre order traversal
 
        inord1(root, res); // calling recursive function with input parameters as root of tree & result vector
        return res;
    }
};

// Iterative

class Solution {
public:
	 vector<int> inorderTraversal(TreeNode* root) {
     
		 vector <int> ans;   // vector to store final inorder traversal
	 
		if(root == NULL)
		   return ans;   // if root null, return empty vector
	 
       
           stack <TreeNode*>  p;   //Declaring the stack of Type TreeNode* to store values from tree
		   p.push(root);  // push root of the tree onto stack
		
        while (!p.empty()) { // traversing till stack is not empty
          
		   TreeNode* node = p.top(); // Initializing node of type TreeNode* to store top value of the stack 
           
		   if (node->left)            // If left side of node exists, push into stack & mark left side of current node as null
			{
               p.push(node->left); 
               node->left = NULL;
            } 
			else                     // if left side is null, then pop the value, store in vector & check on right side
			{
                p.pop();
                ans.push_back(node->val); 
				
				if (node->right)   // If right side of node exists, push into stack & mark right side of current node as null
				{
					p.push(node->right);
					node->right = NULL;
				}
			}
        }
        return ans;
	 }
};

/* visualization of stack & vector in Iterative solution
  
First root is pushed onto stack
  
Node = 7     | Node=6       | Node = 2         | Node = 6        | Node=1           | Node =7         | Node =5		 | Node=3 
Node->left=6 | node->left=2 | node->left=null  | node->left=null | node->left=null  | node->left=null | node->left=3 | node->left=null
push 6		 | push 2		| so pop 2         | so pop 6        |  so pop 1		|	so pop 7  	  | push 3		 |	so pop 3 
							|  & check right   | & check right   |  & check right	| & check right	  |				 | & check right
				            | node->right=null | node->right=1   | node->right=null | node->right = 5 |				 | node->right=null
											   |	push 1		 |					|				  |	

								        		
		 |		|      |	 |	    |       |  ->	|		| ->  
stack p	 |		|  ->  |     |	 -> |	2   |		|		|	    |	    |                   |        |  ->  | 	   |  -> |     |         |      |
		 |		|	   |   6 |      |	6   |		|	6	|	  	|	1   | ->  |       |  -> |        |      |	3  |     |     |  -> ... |      |
		 |	7	|	   |   7 |      |   7   |    	|	7	|	    |	7   |     |   7   |     |   5    |      |	5  |     |  5  |		 |	    |
		 |______|      |_____|      |_______|		|_______|	    |_______|     |_______|     |________|		|______|     |_____|		 |______|	
                          
						 
	vector ans  |_|            			 -> 	     	|2|    ->   |2|6|     -> |2|6|1|     ->  |2|6|1|7|   ->         |2|6|1|7|3|  ->     |2|6|1|7|3|5|4|
			
				vector is 
				empty

*/
