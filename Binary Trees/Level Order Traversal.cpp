// Problem statement Link - https://leetcode.com/problems/binary-tree-level-order-traversal

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
     7   <- level 0
	/ \
   6   5  <- level 1
  /	\  / \
 2  1 3   4 <- level 2
 
 Level order traversal : 7 6 5 2 1 3 4
 
 Input : [7,6,5,2,1,3,4]
 Output : [[7],
           [6, 5]
		   [2, 1, 3, 4]]
*/
   
 // Iterative
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;  // 2D vector to store our final result
        
          if(root == NULL)
		  {
            return res;     // If root is empty, return the result vector
          }
        
        queue<TreeNode*> temp;  // Declaring queue of type TreeNode*
        temp.push(root);         // Push root value into queue
         
        while(temp.size() != 0)   // traverse till queue is not empty
        {
            vector<int> res1;   // declaring vector to store value for each level
             int s =temp.size();  // size of the queue
               
            for(int i=0;i<s;i++)   // looping till size of the queue
            {
                TreeNode* front = temp.front();  // Variable front of type TreeNode* to store tops value of queue
                res1.push_back(front->val);   // stroing that value in vector
                temp.pop();   // delete the value from queue
                
                if(front->left!=NULL){    // If left side of front exists, push it into queue
                    temp.push(front->left);
                }
                if(front->right!=NULL){   // If right side of front exists, push it into queue
                    temp.push(front->right);
                }
            }
            res.push_back(res1); // pushing value of res1 vector for each level into our final vector
        }
        return res; // return the resultant vector
        
    }
};

// Recursive Depth-First Search(DFS) Approach

class Solution {
public:
    vector<vector<int>>ans;   // declaring a 2d vector which will store our final result
	
    void levelord1(TreeNode *root, int level) {
        if (root == NULL) 
		{
			return;          // If root is epmty, return
		}
        if(level==ans.size())
		{
			ans.push_back(vector<int> ());
		}
        ans[level].push_back(root->val);
        levelord1(root->left, level+1);   // recursion on Left subtree
        levelord1(root->right, level+1);  // recursion on right subtree
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
       levelord1(root,0);  // calling recursive function with parameters as root, level as 0
        return ans;
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
				|        |        |        |		|       |		|     |				|	|
                          
						 
vector res1        |_|        ->   |7|  ->   |_|	 ->	 |6|     ->   |6|5|   ->  |_| ->     |2|1|3|4|
			
				vector is 
				empty
				
2D Vector res        |_|               |7|     ->        |7|      -> |7|      ->  |7|  -> |7|
																     |6|5|                |6|5|
																						  |2|1|3|4|
*/