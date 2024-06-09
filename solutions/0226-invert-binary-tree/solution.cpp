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
    void f(TreeNode* node){
        if(node==nullptr){
            return;
        }
        swap(node->left,node->right);
        f(node->left);
        f(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        f(root);
        return root;
    }
};