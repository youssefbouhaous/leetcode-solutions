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
    vector<TreeNode*>ans;
    unordered_map<TreeNode*,pair<TreeNode*,TreeNode*>>tree;
    unordered_map<TreeNode*,TreeNode*>parent;
    unordered_map<int,TreeNode*>node;
    void dfs(TreeNode* n,TreeNode* p){
        node[n->val]=n;
        parent[n]=p;
        tree[n]={nullptr,nullptr};
        if(n->left!=nullptr){
            tree[n].first=n->left;
            dfs(n->left,n);
        }
        if(n->right!=nullptr){
            tree[n].second=n->right;
            dfs(n->right,n);
        }
    }
    unordered_map<TreeNode*,bool>vis;
    void dfs2(TreeNode* n){
        if(n==nullptr){
            return;
        }
        vis[n]=true;
        dfs2(n->left);
        dfs2(n->right);
    }
    TreeNode* pp(TreeNode* n){
        if(parent[n]==n){
            return n;
        }
        return parent[n]=pp(parent[n]);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==nullptr){
            return ans;
        }
        dfs(root,root);
        set<int>dd;
        for(auto x:to_delete){
            dd.insert(x);
            parent[node[x]->left]=node[x]->left;
            parent[node[x]->right]=node[x]->right;
            node[x]->left=nullptr;
            node[x]->right=nullptr;
            
                if(tree[parent[node[x]]].first==node[x]){
                    
                    parent[node[x]]->left=nullptr;
                }
                else{
                    parent[node[x]]->right=nullptr;
                }
                
        }
        for(auto x:tree){
            //cout<<x.first->val<<"parent"<<(parent[node[x.first->val]]->val)<<endl;
            if(!vis[x.first] && !dd.count(x.first->val)){
                ans.push_back(pp(x.first));
                dfs2(pp(x.first));
            }
        }
        return ans;
    }
};