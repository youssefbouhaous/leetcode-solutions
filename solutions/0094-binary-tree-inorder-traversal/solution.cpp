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
    vector<int>ans;
    void f(TreeNode* node){
        if(node==nullptr){
            return;
        }
        bool ff=false;
        if(node->left==nullptr){
            ff=true;
            ans.push_back(node->val);
        }
        if(node->left!=nullptr){
            f(node->left);
            ff=true;
            ans.push_back(node->val);
        }
        if(node->right!=nullptr){
            f(node->right);
            if(!ff)
            ans.push_back(node->val);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        f(root);
        return ans;
    }
};