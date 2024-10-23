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
    int level[100001]={};
    void f(TreeNode* node,int l){
        if(node==nullptr) return;
        level[l]+=node->val;
        f(node->left,l+1);
        f(node->right,l+1);
    }
    void change(TreeNode* node,int l){
        if(node==nullptr) return ;
        int a= ((node->left)==nullptr) ? 0:((node)->left)->val;
        int b= ((node->right)==nullptr) ? 0:((node)->right)->val;
        if(node->left!=nullptr){
            (node->left)->val=level[l+1]-a-b;
            change(node->left,l+1);
        }
        if(node->right!=nullptr){
            (node->right)->val=level[l+1]-a-b;
            change(node->right,l+1);
        }
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        f(root,0);
        root->val=0;
        change(root,0);
        return root;
    }
};