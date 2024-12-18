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
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<pair<long long,long long>,pair_hash>vis;
        unordered_set<pair<long long,long long>,pair_hash>vis2;
        long long p=31;
        long long p2=71;
        long long m=1e9+9;
        int n=s.size();
        vector<long long>p_pow(n);
        vector<long long>p_pow2(n);
        vector<long long>h(n+1);
        vector<long long>h2(n+1);
        p_pow[0]=1;
        p_pow2[0]=1;
        for(int i=1;i<n;i++)p_pow[i]=(p_pow[i-1]*p)%m;
        for(int i=1;i<n;i++)p_pow2[i]=(p_pow2[i-1]*p2)%m;
        for(int i=0;i<n;i++)h[i+1]=(h[i]+((long long)(s[i]-'A'+1))*p_pow[i])%m;
        for(int i=0;i<n;i++)h2[i+1]=(h2[i]+((long long)(s[i]-'A'+1))*p_pow2[i])%m;
        vector<string>ans;
        for(int i=0;i<=n-10;i++){
            long long cur=(h[i+10]-h[i]+m)%m;
            long long cur2=(h2[i+10]-h2[i]+m)%m;
            cur=(cur*p_pow[n-9-i])%m;
            cur2=(cur2*p_pow2[n-9-i])%m;
            if(vis.count({cur,cur2}) && !vis2.count({cur,cur2})){
                ans.push_back(s.substr(i,10));
                vis2.insert({cur,cur2});
            }
            else{
                vis.insert({cur,cur2});
            }
        }
        return ans;
    }
};