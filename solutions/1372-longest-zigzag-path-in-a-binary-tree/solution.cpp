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
    int ans=0;
    void f(TreeNode* r,int v=0,int p=0){
        ans=max(ans,v);
        if(r->right==nullptr && r->left==nullptr){
            return;
        }
        if(p!=1){
            if(r->right!=nullptr) f(r->right,v+1,1);
            if(r->left!=nullptr) f(r->left,1,2);
        }
        else if(p!=2){
            if(r->right!=nullptr) f(r->right,1,1);
            if(r->left!=nullptr) f(r->left,v+1,2);
        }
    }
    int longestZigZag(TreeNode* root) {
        ans=0;
        f(root);
        return ans;
    }
};