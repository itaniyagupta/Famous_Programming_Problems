// Problem Statement Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
 
 Zig ZagLevel order traversal : 7 5 6 2 1 3 4
 
 Input : [7,6,5,2,1,3,4]
 Output : [[7],
           [5, 6]
		   [2, 1, 3, 4]]
*/
 
 //  Recursive Depth-First Search(DFS) Approach
 // Time : O(n); space : O(n)
class Solution {
public:
    vector<vector<int>> res;   // 2D vector to store our final result
    void zigzagLevelOrder(TreeNode* root, int level) {
          
        if(root == NULL) return; // If root is epmty, return
        if(res.size() > level) // if size of vector is more than the level 
        {
            if(level%2 != 0)   // if odd level add the root value in the result array at the beginning of res[level]
            {
              res[level].insert(res[level].begin(), root->val);   
            }
            else           // if even level  add the root value in the result array in the end of the res[level]
            {            
              res[level].push_back(root->val);   
            }
        }
        else
        {
            vector<int> temp;
            temp.push_back(root->val);  // push root value into emporary vector
            res.push_back(temp);     
        }
       zigzagLevelOrder(root->left, level+1);  // recursive calling left subtree
       zigzagLevelOrder(root->right, level+1);  // recursive calling right subtree
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

            zigzagLevelOrder(root, 0); // calling recursive function with parameters - root, level as 0
            return res; 
    }
};

// Iterative Level Order Traversal Approach
// Time : O(n); space : O(n)

class Solution {
public:
	 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if(root == NULL)
		{
			return {};  // If root is empty, return empty vector
		}
        vector<vector<int>> res;  // 2D vector to store our final result
		queue<TreeNode*> p;  // Declaring queue of type TreeNode*
		p.push(root);     // Push root value into queue
		
		bool zigzag  = true;   // boolean variable to toggle traversals. It's true in case of left to right
		
		while(!p.empty()) {   // traverse till queue is not empty
		
			vector<int> level;    // declaring vector to store value for each level
			int size = p.size();   // size of the queue
			while(size--)          // looping till size of the queue
			{
				TreeNode* node = p.front();  // Variable front of type TreeNode* to store top value of queue
                p.pop();                // delete the value from queue
				
                int val = node->val;       // variable to store value of node
				level.push_back(val);       // pushing value into resultant vector
			
				if (node->left != NULL)
					{
					p.push(node->left);      // If left side of front exists, push it into queue
				}
				if (node->right != NULL) 
				{
					p.push(node->right);    // If right side of front exists, push it into queue        
				}
			}
            if (!zigzag) // If bool value of zigzag is false.
            {
                reverse(level.begin(), level.end());  //reverse the value for odd levels
            }
			res.push_back(level);
			zigzag = !zigzag;    // changing the value of zigzag if it's true, it becomes false. If it's false, it becomes true
		}
		return res;
    }
};