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
    TreeNode* f(int l,int r,vector<int>&arr){
        if(l>r){
            return nullptr;
        }
        int m=(l+r)/2;
        TreeNode* node=new TreeNode(arr[m]);
        node->left=f(l,m-1,arr);
        node->right=f(m+1,r,arr);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return f(0,nums.size()-1,nums);
    }
};