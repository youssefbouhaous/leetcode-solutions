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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(root==nullptr){
            return ans;
        }
        ans.push_back(root->val);
        map<int,int>level;
        level[0]=true;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto nxt=q.front();
            int lvl=nxt.second;
            TreeNode* node=nxt.first;
            q.pop();
            if(level[lvl]==0){
                ans.push_back(node->val);
                level[lvl]++;
            }
            else{
                ans[lvl]=(ans[lvl]*(level[lvl])+node->val)/(level[lvl]+1);
                level[lvl]++;
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