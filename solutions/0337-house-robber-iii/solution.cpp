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
    map<pair<TreeNode*,bool>,int>dp;
    int f(TreeNode* node,int o){
        if(node==nullptr){
            return 0;
        }
        if(dp[{node,o}]!=0){
            return dp[{node,o}];
        }
        if(o==0){
        return dp[{node,o}]=max(node->val+f(node->left,1)+f(node->right,1),f(node->left,0)+f(node->right,0));
        }
        return dp[{node,o}]=f(node->left,0)+f(node->right,0);
    }
public:
    int rob(TreeNode* root) {
        return f(root,0);
    }
};