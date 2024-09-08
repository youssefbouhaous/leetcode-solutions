class Solution {
public:
    int findCircleNum(vector<vector<int>>& c) {
       unordered_map<int,vector<int>>g;
       int n=c.size();
       for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && c[i][j]==1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
       }
       unordered_map<int,bool>vis;
       
       int ans=0;
       for(int i=0;i<n;i++){
            if(vis[i]==false){
                ans++;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int nxt=q.front();
                    q.pop();
                    vis[nxt]=true;
                    for(auto x:g[nxt]){
                        if(vis[x]!=true){
                            vis[x]=true;
                            q.push(x);
                        }
                    }
                }
            }
       }
       return ans;
    }
};