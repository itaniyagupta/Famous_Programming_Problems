// Problem Statement Link - https://leetcode.com/problems/binary-tree-preorder-traversal/

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
 Pre order traversal : Root, Left, Right
 
     7   
	/ \
   6   5  
  /	\  / \
 2  1 3   4 
 
 Pre order traversal : 7 6 2 1 5 3 4
 
 Input : [7,6,5,2,1,3,4]
 Output : [7, 6, 2, 1, 5, 3, 4]

*/

 // Recursive
 // Time : O(n)
 
class Solution {
public:
		// recursive function to traverse the tree
     void preord1(TreeNode* root,vector<int>&res)
    {
        if(root == NULL){  // if root is null return
        return;
        }
          res.push_back(root->val); // push root value first
          preord1(root->left, res);  // recursive calling left subtree
          preord1(root->right, res); // recursive calling right subtree
         
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;		 // vector to store final pre order traversal
 
        preord1(root, res);     // calling recursive function with input parameters as root of tree & result vector
        return res;  
        
    }
};


// Iterative
// Time : O(n)

class Solution {
public:
 vector<int> preorderTraversal(TreeNode* root) {
   
      vector<int> ans;  // vector to store final pre order traversal
        
		if(root==NULL) 
		{
			return ans; // if root is null return the ans vector
		}
        stack<TreeNode*> p; //Declaring the stack of Type TreeNode* to store values from tree
        p.push(root);    // push root of the tree onto stack
		
        while(!p.empty()){   // traversing till stack is ot empty
            
			TreeNode* node =p.top(); // Initializing variable of type TreeNode* to store top value of the stack
            p.pop();  // Deleting the top value of stack
            
            if(node ==NULL)
			{
                break;
            }
          
			ans.push_back(node->val);

// Tip: We need the left subtree above right subtree in the stack therefore, 
//we first push the right child of the current node in stack first & then left child so that the 
//left is on top & pushed onto vector first.
           
		   if(node->right  != NULL){
                p.push(node->right);  // traversing right subtree
            }
			
			if(node->left  != NULL)
			{
                p.push(node->left);  // traversing left subtree
            }
        }
        
        return ans;
    }
};

/* visualization of stack & vector in Iterative solution

				First root        while loop starts          This is repeated till                        Finally we have our pre order 
				is pushed       then top element of 	      stack is empty		
				onto stack		 stack is popped out			
							  left of node is pushed
								& then right of node				
	
									
   stack p 	
				|		 |        |        |  ->	|		| ->    |     |  -> |      |     |     | 
				|		 |    ->  |	       |		|	2	|	    | 	  |		|	   |  -> |     | -> ... 	|    |
				|		 |		  |	   6   |		|	1	|		|  1  |     |      |     |  3  |     		|    |
				|	7	 |		  |	   5   |		|	5	|		|  5  |     |   5  |     |  4  |     		|    |
				|________|        |________|		|_______|		|_____|     |______|     |_____|     		|____| 
                          
						 
	vector ans  |_|        ->       |7|_|		->	|7|6|       -> |7|6|2| ->  |7|6|2|1|  ->  |7|6|2|1|5| ->  |7|6|2|1|5|3|4|   
			
				vector is 
				empty

*/