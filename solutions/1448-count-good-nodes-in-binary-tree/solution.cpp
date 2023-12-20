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
    void f(TreeNode* n,int m){
        if(n==nullptr){
            return;
        }
        if(n->val>=m){
            ans++;
        }
        f(n->left,max(m,n->val));
        f(n->right,max(m,n->val));
    }
    int goodNodes(TreeNode* root) {
        f(root,-1000'000);
        return ans;
    }
};