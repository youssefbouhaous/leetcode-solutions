/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    map<TreeNode*,pair<TreeNode*,int>>d;
    void f(TreeNode* node,int level){
        if(node==nullptr) return;
        d[node->left]={node,level+1};
        d[node->right]={node,level+1};
        f(node->left,level+1);
        f(node->right,level+1);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f(root,0);
        if(d[p].first==q) return q;
        if(d[q].first==p) return p;
        if(d[p].second<d[q].second){
            swap(p,q);
        }
        while(p!=root){
            if(d[p].first==q || p==q) return q;
            if(d[p].second==d[q].second){p=d[p].first;q=d[q].first;}
            else{p=d[p].first;}
        }
        return root;
    }
};