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
    int ans=0;
    void f(string& tmp,TreeNode* node){
        if(node->left == nullptr && node->right == nullptr){
            tmp.push_back(node->val+'0');
            ans+=stoi(tmp);
            tmp.pop_back();
            //cout<<tmp<<endl;
            return ;
        }
        tmp.push_back('0'+node->val);
        if(node->left!=nullptr)
        f(tmp,node->left);
        if(node->right!=nullptr)
        f(tmp,node->right);
        tmp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string tmp="";
        f(tmp,root);
        return ans;
    }
};