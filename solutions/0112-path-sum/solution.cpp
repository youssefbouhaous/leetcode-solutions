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
    
    bool f(TreeNode* n,int s,int t){
        if(t==s && n->left==nullptr && n->right==nullptr){
            return true;
        }
        bool ff=false;
        if(n->left!=nullptr){
            ff=f(n->left,s+n->left->val,t);
        }
        if(n->right!=nullptr){
            ff|=f(n->right,s+n->right->val,t);
        }
        return ff;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
             return false;
        }
        return f(root,root->val,targetSum);
    }
};