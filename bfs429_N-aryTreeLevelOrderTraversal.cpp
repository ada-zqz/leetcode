/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(!root) return v;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> vn;
            queue<Node*> qn;
            while(!q.empty()) {
                Node* r = q.front();
                q.pop();
                vn.push_back(r->val);
                for(auto c: r->children) qn.push(c);
            }
            v.push_back(vn);
            q = qn;
        }
        return v;
    }
};
