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
    bool f(TreeNode* a,TreeNode* b){
        if(a==nullptr || b==nullptr){
            return a==b;
        }
        return a->val==b->val && f(a->right,b->left) && f(a->left,b->right); 
    }
    bool isSymmetric(TreeNode* root) {
        return f(root,root);
    }
};