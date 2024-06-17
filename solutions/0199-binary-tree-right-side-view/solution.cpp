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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        queue<pair<TreeNode*,int>>q;
        map<int,bool>l;
        q.push({root,0});
        l[0]=true;
        ans.push_back(root->val);
        while(!q.empty()){
            auto nxt=q.front();
            q.pop();
            if(!l[nxt.second]){
                l[nxt.second]=true;
                ans.push_back(nxt.first->val);
            }
            if(nxt.first->right!=nullptr){
                q.push({nxt.first->right,nxt.second+1});
            }
            if(nxt.first->left!=nullptr){
                q.push({nxt.first->left,nxt.second+1});
            }
        }
        return ans;
    }
};