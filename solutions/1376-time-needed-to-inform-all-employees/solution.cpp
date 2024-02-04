class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(NULL);
    }
    int ans=0;
    void dfs(int x,int val,map<int,vector<int>>&g,vector<int>& info){
        val+=info[x];
        ans=max(ans,val);
        for(auto y:g[x]){
            dfs(y,val,g,info);
        }
    }
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& info) {
        
        map<int,vector<int>>g;
        int b=-1;
        for(int i=0;i<n;i++){
            if(m[i]==-1){
                b=i;
                continue;
            }
            g[m[i]].push_back(i);
        }
        dfs(b,0,g,info);
        return ans;
    }
};