// problem statement link - https://leetcode.com/problems/diameter-of-binary-tree/

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
 
 Input : [7,6,5,2,1,3,4]
 Output : 4
*/
 
 // Recursive
 // Time : O(n)
 
class Solution {
 public:
    int ans =0;  // Initailizing variable to store final diameter with 0
    int height(TreeNode* root) {
        if(root==NULL){  // if root is null return 0
            return 0;
        }
        int left = height(root->left); //calling recursive function on left subtree
        int right = height(root->right); //calling recursive function on rightt subtree
        ans = max(ans, left+right);  //  diameter = max of prev diameter & sum of height of left + right subtree
        return max(left, right) + 1; // adding 1 for current node
    }
    int diameterOfBinaryTree(TreeNode* root) {
    
        if(root==NULL){ // if root is null return 0
            return 0;
        }
       height(root); // calling recursive function diameter
        return ans;
        
    }    
};

// Iterative
// Time : O(n)
 
class Solution {
  public:
	 int diameterOfBinaryTree(TreeNode* root) {
		 if(root==NULL) // if root is null return 0
		 {
            return 0;
         }
        int diameter = 0;  // Initailizing variable to store final diameter with 0
        unordered_map<TreeNode*, int> map;  //  map to store node & its height
        stack<TreeNode*> p;
        p.push(root);
        while (!p.empty()) 
        {
            TreeNode* node = p.top();
            if (node -> left != NULL && map.find(node -> left) == map.end()) // if left node is found in map, push it into stack
            {
                p.push(node -> left);
				 // if right node is found in map, push it into stack
            } else if (node -> right != NULL && map.find(node -> right) == map.end()) 
            {
                p.push(node -> right);
            } 
			else  // if not delete top value of stack
            {
                p.pop(); 
                int leftmax = map[node -> left], rightmax = map[node -> right];
                map[node] = max(leftmax, rightmax) + 1; //height of curr subtree
                diameter = max(diameter, leftmax + rightmax);
            }
        }
        return diameter;
	 }
};
	