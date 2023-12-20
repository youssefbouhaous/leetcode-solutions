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
    vector<int>a;
    vector<int>b;
    void f(TreeNode* n,vector<int>&b){
        if(n==nullptr){
            return;
        }
        if(n->left==nullptr && n->right==nullptr){
            b.push_back(n->val);
            return;
        }
        f(n->left,b);
        f(n->right,b);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        f(root1,a);
        f(root2,b);
        if(a.size()!=b.size()){
            return false;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};