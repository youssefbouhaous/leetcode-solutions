class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        map<int,int>see;
        vector<int>ans(n,1e5+1);
        for(int i=n-1;i>-1;i--){
            see[t[i]]=i;
            for(int j=t[i]+1;j<=100;j++){
                if(see[j]!=0){
                    ans[i]=min(ans[i],see[j]-i);
                }
            }
            if(ans[i]==1e5+1){
                ans[i]=0;
            }
        }
        return ans;
    }
};