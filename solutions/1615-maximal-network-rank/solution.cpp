class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans=0;
        map<int,vector<int>>g;
        for(int i=0;i<roads.size();i++){
            g[roads[i][1]].push_back(roads[i][0]);
            g[roads[i][0]].push_back(roads[i][1]);
        }
        
        for(int i=0;i<n;i++){
            if(!g[i].empty()){
                sort(g[i].begin(),g[i].end());
            }
        }
        for(int i=0;i<n;i++){
            for(auto x:g[i]){
                ans=max(ans,(int)g[i].size()+(int)g[x].size()-1);
            }
            for(int j=0;j<n;j++){
               
                if(i!=j && binary_search(g[i].begin(),g[i].end(),j)==0){
                    ans=max(ans,(int)(g[i].size()+g[j].size()));
                }
            }
        }
        return ans;
    }
};