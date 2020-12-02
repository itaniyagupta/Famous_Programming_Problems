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
 
 //  Recursive Depth-First Search(DFS) Approach
 // Time : O(n); space : O(n)
class Solution {
public:
    vector<vector<int>> res;
    void zigzagLevelOrder(TreeNode* root, int level) {
          
        if(root == NULL) return;
        if(res.size() > level)
        {
            if(level%2 != 0)
            {
              res[level].insert(res[level].begin(), root->val);   
            }
            else
            {
              res[level].push_back(root->val);   
            }
        }
        else
        {
            vector<int> temp;
            temp.push_back(root->val);
            res.push_back(temp);
        }
       zigzagLevelOrder(root->left, level+1);
       zigzagLevelOrder(root->right, level+1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

            zigzagLevelOrder(root, 0);
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
			return {};
		}
         vector<vector<int>> res;
		queue<TreeNode*> p;
		p.push(root);
		
		bool zigzag  = true;
		
		while(!p.empty()) {
		
			vector<int> level;
			int size = p.size();
			while(size--)
			{
				TreeNode* node = p.front();
                p.pop();
				
                int val = node->val;
				level.push_back(val);
			
				if (node->left != NULL)
					{
					p.push(node->left);
				}
				if (node->right != NULL) 
				{
					p.push(node->right);
				}
			}
            if (!zigzag) 
            {
                reverse(level.begin(), level.end());
            }
			res.push_back(level);
			zigzag = !zigzag;
		}
		return res;
    }
};