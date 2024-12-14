class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int ans=0;
        int n=p.size();
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            map<long double,int>m;
            for(int j=i+1;j<n;j++){
                if(p[i][0]==p[j][0]){
                    m[INT_MAX]++;
                    ans=max(ans,m[INT_MAX]+1);
                }
                else{
                    long double a=((double)p[i][1]-(double)p[j][1])/((double)p[i][0]-(double)p[j][0]);
                    m[a]++;
                    ans=max(m[a]+1,ans);
                }
            }
        }
        return ans;
    }
};