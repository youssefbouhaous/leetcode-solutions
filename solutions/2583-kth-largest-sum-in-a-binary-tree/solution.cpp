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
    map<int,long long int>level;
    void f(TreeNode* node,int l){
        if(node==nullptr) return ;
        level[l]+=node->val;
        f(node->left,l+1);
        f(node->right,l+1);
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        f(root,1);
        long long int ans=-1;
        vector<long long int>st;
        for(auto x:level){
            st.push_back(x.second);
        }
        sort(st.begin(),st.end());
        if(st.size()<k) return -1;
        return st[((int)st.size())-k];
    }
};