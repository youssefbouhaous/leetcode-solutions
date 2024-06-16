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
    int ans=1000000;
    void dfs(TreeNode* node,TreeNode* f){
        if(node!=f){
            ans=min(abs(node->val-f->val),ans);
        }
        if(node->left!=nullptr){
            dfs(node->left,f);
        }
        if(node->right!=nullptr){
            dfs(node->right,f);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root,root);
        if(root->left!=nullptr){
            getMinimumDifference(root->left);
        }
        if(root->right!=nullptr){
            getMinimumDifference(root->right);
        }
        return ans;
    }
};