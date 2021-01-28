//Problem Statement Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
     7   <- level 0  Height 1
	/ \
   6   5  <- level 1  Height 2
  /	\  / \
 2  1 3   4 <- level 2  Height 3
 
 Input : [7,6,5,2,1,3,4]
 Output : 3 
 
*/
 
 
// Recursive
// Time : O(n); Space: O(n)
	
class Solution {
 public:
	int height(TreeNode* root) {
    if(root == NULL)  // if root is empty return 0
	{
		return 0;
	}
	    int left = height(root->left);  //calling recursive function on left subtree
        int right = height(root->right); //calling recursive function on right subtree
        int height = max(left , right); // finding max value out of left & right subtree
        return height + 1;  // adding 1 for current node
    }
};

// Iterative
// Time : O(n); Space: O(n)

class Solution {
 public:
	int height(TreeNode* root) { 
		if (root == NULL) // if root is empty return 0
		{
			return 0;
		}
		queue<TreeNode*> q; // queue of type TreeNode* to store tree node values
		q.push(root); // push root value to queue
		int height = 0; // intializing height as 0
		
		while(!q.empty()) {  // traversing till queue is empty
			int size = q.size(); // size of queue indicates number of nodes at current level. 
			if (size == 0) 
			{
				return height;  // if size is 0 return intial height
			}
			height = height + 1;  // adding 1 to height for current node
			
			while (size > 0) // till queue size is not 0 or level is completely traversed // loop runs for each level
			{ 
				TreeNode* node = q.front(); // variable of type Treenode* to store top value of queue
				q.pop(); // deleting value from queue
				
				if (node->left != NULL)  // if left of current node exists, push it into queue
				{
					q.push(node->left);
				}
				
				if (node->right != NULL)  // if right of current node exists, push it into queue
				{ 
					q.push(node->right);
				}
				size--; // decrementing size by 1
			}
		}
		return height; // return height of tree
	}
};

/* visualization of Queue & vector in Iterative solution

				First root          while loop starts                 This is repeated till queue               
			    is pushed				then size of queue is taken        becomes empty
				onto Queue				Till the size of queue,
									 for loop runs & for each loop
									  top element of queue			    						    
										is popped out  
								     left of node is pushed 							
								     & then right is pushed           
								         onto queue				       
	
														
 Queue temp 	    			      				   				
														     		
				|		 |        |        |  ->	|		|   ->  |  4  |
				|		 |    ->  |	       |		|	1	|		|  3  |   .... ->  	|	|
				|		 |		  |	   5   |		|	2	|	    |  1  |      		|	|
				|	7	 |		  |	   6   |		|	5	|		|  2  |				|	|
				|        |        |        |		|       |		|     |			 	|	|
                          Level 0 							Level 1				Level 2 
						   done                              done                done
Height             1        ->                                 2         -> 3    
						 
*/