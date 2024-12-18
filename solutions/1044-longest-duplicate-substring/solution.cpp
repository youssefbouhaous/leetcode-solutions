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
    string longestDupSubstring(string s) {
        int n=s.size();
        vector<long long>h(n+1,0);
        vector<long long>h2(n+1,0);
        vector<long long>p_pow(n);
        vector<long long>p_pow2(n);
        long long int p=31;
        long long int p2=71;
        p_pow[0]=1;
        p_pow2[0]=1;
        long long int m=1e9+9;
        for(int i=1;i<n;i++) {
            p_pow[i]=(p_pow[i-1]*p)%m;
            p_pow2[i]=(p_pow2[i-1]*p2)%m;}
        for(int i=0;i<n;i++) {
            h[i+1]=(h[i]+(s[i]-'a'+1)*p_pow[i])%m;
            h2[i+1]=(h2[i]+(s[i]-'a'+1)*p_pow2[i])%m;
        }
        string ans="";
        int l=1;
        int r=n-1;
        while(l<=r){
            int mm=(l+r)/2;
            unordered_set<pair<long long, long long>,pair_hash> hs;
            bool found=false;
            for(int i=0;i<=n-mm;i++){
                long long int cur=(h[mm+i]-h[i]+m)%m;
                long long int cur2=(h2[mm+i]-h2[i]+m)%m;
                cur=(cur*p_pow[n-i-1])%m;
                cur2=(cur2*p_pow2[n-i-1])%m;
                if(hs.count({cur,cur2})){
                    if(mm>ans.size())
                    ans=s.substr(i,mm);
                    found=true;
                    break;
                }
                hs.insert({cur,cur2});
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