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
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        vector<int>ans; 
        if(root==nullptr){
            return ans;
        }
        int i=0;
        ans.push_back(root->val);
        while(!q.empty()){
            TreeNode* next=q.front().first;
            int l=q.front().second;
            q.pop();
            
            if(ans.size()<=l){
                if(next->left!=nullptr){
                    ans.push_back((next->left)->val);
                    q.push({next->left,l+1});
                }
                if(next->right!=nullptr){
                    q.push({next->right,l+1});
                    if(ans.size()<=l){
                        ans.push_back((next->right)->val);
                    }
                    else{
                        ans[l]=(next->right)->val;
                    }
                }
            }
            else{
                if(next->left!=nullptr){
                    ans[l]=((next->left)->val);
                    q.push({next->left,l+1});
                }
                if(next->right!=nullptr){
                    q.push({next->right,l+1});
                    ans[l]=(next->right)->val;
                }
            }
        }
        return ans;
    }
};