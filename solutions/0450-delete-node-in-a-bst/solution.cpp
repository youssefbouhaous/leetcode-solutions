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
    int k;
    TreeNode* f(TreeNode* a){
        if(a->left==nullptr){
            return a;
        }
        return f(a->left);
    }
    void dfs(TreeNode* u,TreeNode* par){
        if(u==nullptr){
            return;
        }
        if(u->val==k){
            if(u->val<par->val){
                if(u->right==nullptr){
                    par->left=u->left;
                }
                else{
                    par->left=u->right;
                    TreeNode* mostLeft=f(u->right);
                    if(mostLeft!=nullptr){
                        mostLeft->left=u->left;
                    }
                }
            }
            else{
                if(u->right==nullptr){
                    par->right=u->left;
                }
                else{
                    par->right=u->right;
                    TreeNode* mostLeft=f(u->right);
                    if(mostLeft!=nullptr){
                        mostLeft->left=u->left;
                    }
                }
            }
        }
        dfs(u->left,u);
        dfs(u->right,u);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        k=key;
        if(root==nullptr){
            return root;
        }
        if(root->val==k){
            if(root->right==nullptr){
                root=root->left;
            }
            else if(root->left==nullptr){
                root=root->right;
            }
            else{
                TreeNode* l=root->left;
                root=root->right;
                TreeNode* mostLeft=f(root);
                mostLeft->left=l;
            }
        }
        else{
            dfs(root,nullptr);
        }
        return root;
    }
};