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
    unordered_map<int,pair<int,int>>tree;
    void construct(TreeNode* node,int ele){
        TreeNode* left;
        TreeNode* right;
        if(tree[ele].first){
            right=new TreeNode(tree[ele].first);
            node->right=right;
            construct(right,tree[ele].first);
        }
        if(tree[ele].second){
            left=new TreeNode(tree[ele].second);
            node->left=left;
            construct(left,tree[ele].second);
        }

    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,bool>v;
        for(auto x:d){
            v[x[1]]=true;
            if(x[2]==1){
                tree[x[0]].second=x[1];
            }
            else{
                tree[x[0]].first=x[1];
            }
        }
        int parent;
        for(auto x:d){
            if(!v[x[0]]){
                parent=x[0];
                break;
            }
        }
        TreeNode* root=new TreeNode(parent);
        construct(root,parent);
        return root;
    }
};