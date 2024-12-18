class Solution {
    struct pair_hash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        long long p=293;
        long long p2=113;
        long long mod=1e9+7;
        int n=nums1.size();
        int m=nums2.size();
        int nm=max(n,m);
        vector<long long>pp(nm);
        vector<long long>pp2(nm);
        vector<long long>h1(nm+1);
        vector<long long>h12(nm+1);
        vector<long long>h2(nm+1);
        vector<long long>h22(nm+1);
        pp[0]=1;
        pp2[0]=1;
        for(int i=1;i<nm;i++)pp[i]=(pp[i-1]*p)%mod;
        for(int i=1;i<nm;i++)pp2[i]=(pp2[i-1]*p2)%mod;
        for(int i=0;i<n;i++)h1[i+1]=(h1[i]+(nums1[i]+1)*pp[i])%mod;
        for(int i=0;i<n;i++)h12[i+1]=(h12[i]+(nums1[i]+1)*pp2[i])%mod;
        for(int i=0;i<m;i++)h2[i+1]=(h2[i]+(nums2[i]+1)*pp[i])%mod;
        for(int i=0;i<m;i++)h22[i+1]=(h22[i]+(nums2[i]+1)*pp2[i])%mod;
        int l=0;
        int r=min(n,m);
        int ans=0;
        while(l<=r){
            int mm=(l+r)/2;
            unordered_set<pair<long long ,long long>,pair_hash>st;
            for(int i=0;i<=min(n-mm,n-1);i++){
                long long cur=(h1[i+mm]-h1[i]+mod)%mod;
                long long cur2=(h12[i+mm]-h12[i]+mod)%mod;
                cur=(cur*pp[nm-i-1])%mod;
                cur2=(cur2*pp2[nm-i-1])%mod;
                st.insert({cur,cur2});
            }
            bool found=false;
            for(int i=0;i<=min(m-mm,m-1);i++){
                long long cur=(h2[i+mm]-h2[i]+mod)%mod;
                long long cur2=(h22[i+mm]-h22[i]+mod)%mod;
                cur=(cur*pp[nm-i-1])%mod;
                cur2=(cur2*pp2[nm-i-1])%mod;
                if(st.count({cur,cur2})){
                    found=true;
                    ans=max(ans,mm);
                    break;
                }
            }
            if(found){
                l=mm+1;
            }
            else{
                r=mm-1;
            }
        }
        return ans;
    }
};