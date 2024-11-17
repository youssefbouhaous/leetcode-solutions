/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)return root;
        map<Node*,int>level;
        queue<Node*>q;
        q.push(root);
        level[root]=1;
        while(!q.empty()){
            auto nxt=q.front();q.pop();
            if(!q.empty() && level[q.front()]==level[nxt]){
                nxt->next=q.front();
            }
            if(nxt->left!=nullptr){
                q.push(nxt->left);
                level[nxt->left]=level[nxt]+1;
            }
            if(nxt->right!=nullptr){
                q.push(nxt->right);
                level[nxt->right]=level[nxt]+1;
            }
        }
        return root;
    }
};