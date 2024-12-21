class Solution {
    long long p=293;
    long long mod=1e9+7;
    int n;
    long long getHash(int l,int r,vector<long long>&pp,vector<long long>&h){
        long long hash=(h[r+1]-h[l]+mod)%mod;
        hash=(hash*pp[n-r-1])%mod;
        return hash;
    }
    bool compare(int s1,int s2,int l,vector<long long>&pp,vector<long long>&h){
        return getHash(s1,s1+l-1,pp,h)==getHash(s2,s2+l-1,pp,h);
    }
public:
    int beautifulSplits(vector<int>& nums) {
        n=nums.size();
        vector<long long>pp(n+1,1);
        vector<long long>h(n+1);
        pp[0]=1;
        for(int i=1;i<n;i++)pp[i]=(pp[i-1]*p)%mod;
        for(int i=0;i<n;i++)h[i+1]=(h[i]+(nums[i]+1)*pp[i])%mod;
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                 int l1=i;
                 int l2=j-i;
                 int l3=n-j;
                 bool ans1=false,ans2=false;
                 if(l1<=l2 && compare(0,i,l1,pp,h)){
                    ans1=true;
                 }
                 if(l2<=l3 && compare(i,j,l2,pp,h)){
                    ans2=true;
                 }
                 if(ans1 || ans2){
                    ans++;
                 }
            }
        }
        return ans;
    }
};