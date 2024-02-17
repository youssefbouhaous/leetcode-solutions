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
    map<int,vector<int>>g;
    map<int,bool>v;
    void bfs(TreeNode* n){
        if(n==nullptr){
            return;
        }
        if(n->left!=nullptr){
            g[n->val].push_back((n->left)->val);
            g[(n->left)->val].push_back(n->val);
        }
        if(n->right!=nullptr){
            g[n->val].push_back((n->right)->val);
            g[(n->right)->val].push_back(n->val);
        }
        bfs(n->left);
        bfs(n->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            vector<int>ans;
            ans.push_back(target->val);
            return ans;
        }
        bfs(root);
        queue<pair<int,int>>q;
        q.push({target->val,0});
        vector<int>ans;
        cout<<root->val<<" "<<target->val<<" "<<k<<endl;
        v[target->val]=true;
        while(!q.empty()){
            auto nxt=q.front();
            q.pop();
            int d=nxt.second;
            int e=nxt.first;
            cout<<e<<endl;
            for(auto x:g[e]){
                if(!v[x] && d+1==k){
                    ans.push_back(x);
                    cout<<e<<" "<<x<<endl;
                }
                else if(!v[x]){
                    q.push({x,d+1});
                }
                v[x]=true;
            }
        }
        return ans;
    }
};