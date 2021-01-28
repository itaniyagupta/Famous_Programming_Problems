// Problem Statement Link - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
 
 Reverse Level order traversal : 2 1 3 4 6 5 7 
 
 Input : [7,6,5,2,1,3,4]
 Output :   [
			[2,1,3,4],
			[6,5],
			[7]	
			]
*/
 
// Time : O(n)

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
           vector<vector<int>> res;
        
          if(root == NULL){
            return res;
        }
        
        queue<TreeNode*> temp;
        temp.push(root);
        
        while(temp.size() != 0)
        {
            vector<int> res1;
             int s =temp.size();
               
            for(int i=0;i<s;i++)
            {
                TreeNode* front = temp.front();
                temp.pop();
                res1.push_back(front->val);
                
                if(front->left!=NULL){
                    temp.push(front->left);
                }
                if(front->right!=NULL){
                    temp.push(front->right);
                }
               
            }
            res.push_back(res1);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


/* visualization of Queue & vector in Iterative solution

				First root          while loop starts                 This is repeated till queue              Reverse the res vector
				is pushed         then top element of queue			    becomes empty						   we have our reverse
				onto Queue			is popped out  																	level order 
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
				
2D Vector res        |_|               |7|     ->        |7|      -> |7|      ->  |7|  -> |7|             -> |2|1|3|4|
																     |6|5|                |6|5|				  |6|5|
																						  |2|1|3|4|            |7|

*/