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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root=new TreeNode(postorder.back());
        vector<int>il;
        vector<int>ir;
        vector<int>pl;
        vector<int>pr;
        bool f=false;
        unordered_map<int,int>d;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==postorder.back()){
                f=true;continue;
            }
            if(f){ir.push_back(inorder[i]);d[inorder[i]]=1;}
            else{il.push_back(inorder[i]);d[inorder[i]]=2;}
        }
        for(auto x:postorder){
            if(d[x]==1){pr.push_back(x);}
            if(d[x]==2){pl.push_back(x);}
        }
        if(pl.size()>0) root->left=buildTree(il,pl);
        if(pr.size()>0) root->right=buildTree(ir,pr);
        return root;
    }
};