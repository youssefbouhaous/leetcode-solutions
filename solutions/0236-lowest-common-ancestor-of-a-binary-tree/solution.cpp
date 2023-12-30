/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
    int tin[100'005],tout[100'005];
    int timer,id;
    map<TreeNode*,int>d;
    int up[100'005][21];
    map<TreeNode*,TreeNode*>parent;
    void dfs(TreeNode* u,TreeNode* par=nullptr){
        if(u==nullptr){
            return;
        }
        parent[u]=par;
        d[u]=id;id++;
        dfs(u->left,u);
        dfs(u->right,u);
    }
    void dfsa(TreeNode* u){
        if(u==nullptr){
            return;
        }
        tin[d[u]]=++timer;
        up[d[u]][0]=d[u];
        int o=d[u];
        for(int i=1;i<21;i++){
            up[o][i]=up[up[o][i-1]][i-1];
        }
        dfsa(u->left);
        dfsa(u->right);
        tout[d[u]]=++timer;
    }
    bool is_ancestor(TreeNode* u,TreeNode* v){
        return tin[d[u]]<=tin[d[v]] && tout[d[u]]>=tout[d[v]];
    }
    TreeNode* lca(TreeNode* a, TreeNode* b){
        if(is_ancestor(a,b)){
            return a;
        }
        if(is_ancestor(b,a)){
            return b;
        }
        TreeNode* p=a;
        while(!is_ancestor(p,b) && p!=nullptr){
            p=parent[p];
        }
        return p;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        timer=0;
        id=1;
        dfs(root);
        dfsa(root);
        return lca(p,q);
    }
};