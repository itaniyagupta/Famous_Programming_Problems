// Problem Statement Link - https://leetcode.com/problems/binary-tree-postorder-traversal/


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
 Post order traversal : Left, right, root
 
     7   
	/ \
   6   5  
  /	\  / \
 2  1 3   4 
 
 Post order traversal : 7 6 5 2 1 3 4
 
 Input : [7,6,5,2,1,3,4]
 Output : [2, 1, 6, 3, 4, 5, 7]

*/
 
 
// Recursive
// Time : O(n) 
class Solution {
 public:
    // recursive function to traverse the tree
    void postord1(TreeNode* root,vector<int>&res)
    {
        if(root == NULL){ // if root is null return
        return;
        }
        
          postord1(root->left, res);  // recursive calling left subtree
          postord1(root->right, res); // recursive calling right sutree
          res.push_back(root->val); // push root value in the end
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;  // vector to store final post order traversal
 
        postord1(root, res); // calling recursive function with input parameters as root of tree & result vector
        return res;  
    }
};

// Iterative

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
		vector<int> ans; // vector to store final post order traversal
        
		if(root==NULL) 
		{
			return ans; // if root is null return the res vector
		}
        stack<TreeNode*> p;  //Declaring the stack of Type TreeNode* to store values from tree 
        p.push(root);    // push root of the tree onto stack
		
        while(!p.empty()){  // traversing till stack is not empty
            
			TreeNode* node = p.top(); // Initializing variable of type TreeNode* to store top value of the stack
            p.pop(); // Deleting the top value of stack
            
            if(node == NULL)
			{
                break;
            }
            ans.push_back(node->val); // push the value of node variale onto vector

// Tip: We need the right subtree above left subtree in the stack therefore, 
//we first push the left child of the current node in stack first & then right child so that the 
//right is on top & pushed onto vector first.  
			
            if(node->left  != NULL)
			{
                p.push(node->left); // traversing left subtree
            }
            if(node->right  != NULL){
                p.push(node->right);  // traversing right subtree
            }
        }
        reverse(ans.begin(),ans.end()); // reversing the values in the vector
        return ans;
    }
};

/* visualization of stack & vector in Iterative solution

				First root        while loop starts          This is repeated till                           Finally reverse the vector
				is pushed       then top element of 	      stack is empty					  		   	   & we have our post order 
				onto stack		 stack is popped out			
							  left of node is pushed
								& then right of node				
	
									
   stack p 					       		
										
				|		 |        |        |  ->	|		| ->    |     |  -> |      |     |     | 
				|		 |    ->  |	       |		|	4	|	    | 	  |		|	   |  -> |     | -> ... 	|    |
				|		 |		  |	   5   |		|	3	|		|  3  |     |      |     |  1  |     		|    |
				|	7	 |		  |	   6   |		|	6	|		|  6  |     |   6  |     |  2  |     		|    |
				|________|        |________|		|_______|		|_____|     |______|     |_____|     		|____| 
                          
						 
	vector ans  |_|        ->       |7|_|		->	|7|5|       -> |7|5|4| ->  |7|5|4|3|  ->  |7|5|4|3|6| -> |7|5|4|3|6|1|2|   -> |2|1|6|3|4|5|7|
			
				vector is 
				empty

*/