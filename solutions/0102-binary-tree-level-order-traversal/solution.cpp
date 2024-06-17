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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        //ans.push_back({root->val});
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            auto nxt=q.front();
            int lvl=nxt.second;
            TreeNode* node=nxt.first;
            q.pop();
            if(lvl>ans.size()){
                ans.push_back({node->val});
            }
            else{
                ans[lvl-1].push_back(node->val);
            }
            if(node->left!=nullptr){
                q.push({node->left,lvl+1});
            }
            if(node->right!=nullptr){
                q.push({node->right,lvl+1});
            }
        }
        return ans;
    }
};