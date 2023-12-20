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
 #define ll long long int
class Solution {
public:
    int ans=0;
    map<int,bool>mp;
    void g(TreeNode* n,ll m,int & t){
        if(n==nullptr){
            return;
        }
        if(n->val+m==(ll)t){
            ans++;
        }
        g(n->left,n->val+m,t);
        g(n->right,n->val+m,t);
    }
    void f(TreeNode* n ,int& t){
        if(n==nullptr){
            return;
        }
        
        g(n,0,t);
        f(n->left,t);
        f(n->right,t);
    }
    int pathSum(TreeNode* root, int targetSum) {
        f(root,targetSum);
        return ans;
    }
};