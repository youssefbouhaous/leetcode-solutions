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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        vector<int>pl;
        vector<int>pr;
        vector<int>il;
        vector<int>ir;
        unordered_map<int,int>d;
        bool f=false;
        for(int i=0;i<preorder.size();i++){
            if(inorder[i]==preorder[0]){
                f=true;continue;
            }
            if(f){ ir.push_back(inorder[i]);d[inorder[i]]=1;}
            else {il.push_back(inorder[i]);d[inorder[i]]=2;}
        }
        for(auto x:preorder){
                if(d[x]==1){pr.push_back(x);}
                if(d[x]==2){pl.push_back(x);}
        }
        if(pl.size()>0)
        root->left=buildTree(pl,il);
        if(pr.size()>0)
        root->right=buildTree(pr,ir);
        return root;
    }
};