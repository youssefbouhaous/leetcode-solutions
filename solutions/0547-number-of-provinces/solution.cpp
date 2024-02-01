class Solution {
public:
    void f(int x,map<int,vector<int>>&g,vector<bool>&v){
        if(v[x]){
            return;
        }
        v[x]=true;
        for(auto y:g[x]){
            f(y,g,v);
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        vector<bool>v(n+1);
        map<int,vector<int>>g;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++ ){
                if(a[i][j]==1){
                    g[i+1].push_back(j+1);
                    g[j+1].push_back(i+1);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!v[i]){
                ans++;
                f(i,g,v);
            }
        }
        return ans;
    }
};