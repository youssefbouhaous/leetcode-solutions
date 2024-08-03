class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int ans=0;
        for(int i=0;i<=n;i++){
            map<int,int>d;
            for(auto x:pick){
                if(x[0]==i){
                    d[x[1]]++;
                }
            }
            for(auto x:d){
                if(x.second>=i+1){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};