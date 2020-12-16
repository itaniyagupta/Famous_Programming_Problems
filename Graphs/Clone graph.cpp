// Problem statement link - https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int,Node*> m;
    Node* cloneGraph(Node* node) {
        
        if(node==NULL) return NULL;
        if(m[node->val]==NULL)
        {
          Node* p=new Node(node->val);
          m[node->val]=p;
          vector<Node*> q;
          for(auto x:node->neighbors)
          q.push_back(cloneGraph(x));
          p->neighbors=q;
        }
        return m[node->val];
        
    }
};