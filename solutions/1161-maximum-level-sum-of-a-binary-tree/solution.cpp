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
    int maxLevelSum(TreeNode* root) {
        long long int ans=root->val;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        map<int,long long int>d;
        int r=1;
        while(!q.empty()){
            TreeNode* next=q.front().first;
            int l=q.front().second;
            d[l]+=next->val;
            q.pop();
            if(next->left!=nullptr){
                q.push({next->left,l+1});
            }
            if(next->right!=nullptr){
                q.push({next->right,l+1});
            }
        }
        for(auto x:d){
            if(x.second>ans){
                r=x.first+1;
                ans=x.second;
            }
        }
        return r;
    }
};