class Solution {
    int s,m,n;
    vector<pair<int,int>>v;
    int dp[601][101][101];
    int f(int o,int z,int i){
        if(i>=s){
            return 0;
        }
        if(dp[i][o][z]!=-1)return dp[i][o][z];
        if(o+v[i].first<=n && z+v[i].second<=m)
        return dp[i][o][z]=max({1+f(o+v[i].first,z+v[i].second,i+1),f(o,z,i+1)});
        return dp[i][o][z]=f(o,z,i+1);
    }
public:
    int findMaxForm(vector<string>& strs, int mm, int nn) {
        for(int i=0;i<601;i++)for(int j=0;j<101;j++)for(int l=0;l<101;l++)dp[i][j][l]=-1;
        s=strs.size();
        m=mm;
        n=nn;
        for(auto x:strs){
            int one=0;
            int zero=0;
            for(auto y:x){
                if(y=='1'){
                    one++;
                }
                else{
                    zero++;
                }
            }
            v.push_back({one,zero});
        }
        return f(0,0,0);
    }
};