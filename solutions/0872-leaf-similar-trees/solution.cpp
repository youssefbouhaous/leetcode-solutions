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
    vector<int>r1;
    vector<int>r2;
    void f1(TreeNode* r){
        if(r==nullptr){
            return ;
        }
        if(r->left==nullptr && r->right==nullptr){
            r1.push_back(r->val);
        }
        f1(r->left);
        f1(r->right);
    }
    void f2(TreeNode* r){
        if(r==nullptr){
            return ;
        }
        if(r->left==nullptr && r->right==nullptr){
            r2.push_back(r->val);
        }
        f2(r->left);
        f2(r->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        r1.clear();
        r2.clear();
        f1(root1);   
        f2(root2);
        if(r1.size()!=r2.size()){
            return false;
        }   
        
        for(int i=0;i<r1.size();i++){
            if(r1[i]!=r2[i]){
                return false;
            }
        }
        return true;
    }
};