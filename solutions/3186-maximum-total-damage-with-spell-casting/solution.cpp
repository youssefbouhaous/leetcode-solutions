class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int,long long>d;
        set<int>st;
        for(auto x:power){
            d[x]++;
            st.insert(x);
        }
        long long ans=0;
        map<int,long long>dp;
        vector<int>v;
        for(auto x:st){
            v.push_back(x);
        }
        dp[0]=d[v[0]]*v[0];
        if(v.size()>=2){
            dp[1]=d[v[1]]*v[1];
            if(v[1]!=v[0]+1 && v[1]!=v[0]+2 && v[1]!=v[0]-1 && v[1]!=v[0]-2){
                dp[1]+=dp[0];
            }
            else{
                dp[1]=max(dp[0],dp[1]);
            }
            for(int i=2;i<v.size();i++){
                dp[i]=d[v[i]]*v[i];
                if(v[i]!=v[i-1]+1 && v[i]!=v[i-1]+2 && v[i]!=v[i-1]-1 && v[i]!=v[i-1]-2){
                    dp[i]+=dp[i-1];
                }
                else if(v[i]!=v[i-2]+1 && v[i]!=v[i-2]+2 && v[i]!=v[i-2]-1 && v[i]!=v[i-2]-2){
                    dp[i]+=dp[i-2];
                }
                else if(i>=3){
                    dp[i]+=dp[i-3];
                }
                dp[i]=max({dp[i],dp[i-1],dp[i-2]});
            }
        }
        for(auto x:dp){
            //cout<<x.first<<": "<<x.second<<endl;
            ans=max(ans,x.second);
        }
        return ans;
    }
};