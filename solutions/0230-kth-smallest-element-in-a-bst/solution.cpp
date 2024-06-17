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
    int count=0;
    TreeNode* ans;
    void dfs(TreeNode* node,int k){
        if(node==nullptr){
            return;
        }
        
        bool f=false;
        if(node->left==nullptr){
            count++;
            f=true;
            if(count==k){
                if(!ans)
                ans=node;
            }
        }
        if(node->left!=nullptr){
            dfs(node->left,k);
            if(!f)
            count++;
            f=true;
            if(count==k){
                if(!ans)
                ans=node;
            }
        }
        if(node->right!=nullptr){
            dfs(node->right,k);
            if(!f)
            count++;
            if(count==k){
                if(!ans)
                ans=node;
            }
        }
        if(count==k){
            if(!ans)
            ans=node;
        }
        //cout<<count<<" - "<<node->val<<endl;
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans->val;
    }
};