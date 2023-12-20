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
    void f(TreeNode* n,int c){
        if(n==nullptr){
            return;
        }
        ans=max(ans,c);
        f(n->left,c+1);
        f(n->right,c+1);
    }
    int maxDepth(TreeNode* root) {
        f(root,1);
        return ans;
    }
};