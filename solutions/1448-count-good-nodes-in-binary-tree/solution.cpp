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
class Solution {
public:
    int n=1;
    void f(TreeNode* r,TreeNode* p){
        if(r==nullptr){
            return;
        }
        if((r->val)>=(p->val)){
            n++;
        }
        r->val=max(r->val,p->val);
        f(r->left,r);
        f(r->right,r);
    }
    int goodNodes(TreeNode* root) {
        f(root->left,root);
        f(root->right,root);
        return n;
    }
};