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
    vector<string>ans;
    void f(TreeNode* node,string& s){
        if(node->left==nullptr&&node->right==nullptr){
            ans.push_back(s);
            return;
        }
        if(node->left!=nullptr){
            string a=to_string(node->left->val);
            s+="->"+a;
            f(node->left,s);
            s.pop_back();
            s.pop_back();
            for(int i=0;i<a.size();i++)s.pop_back();
        }
        if(node->right!=nullptr){
            string a=to_string(node->right->val);
            s+="->"+a;
            f(node->right,s);
            s.pop_back();
            s.pop_back();
            for(int i=0;i<a.size();i++)s.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr)return ans;
        string s=to_string(root->val);
        f(root,s);
        return ans;
    }
};