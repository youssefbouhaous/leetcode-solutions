#include <bits/stdc++.h>
using Hash = __int128;
struct HashFunction {
    std::size_t operator()(const __int128& x) const {
        return std::hash<int64_t>()(x >> 64) ^ std::hash<int64_t>()(x & 0xFFFFFFFFFFFFFFFF);
    }
};

struct Equal {
    bool operator()(const __int128& lhs, const __int128& rhs) const {
        return lhs == rhs;
    }
};
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int pp) {
        const Hash p = 293;
        const Hash m = 984162944621615797;
        int n=nums.size();
        vector<Hash>pow(n+1,1);
        vector<Hash>h(n+1,0);
        for(int i=1;i<=n;i++){
            pow[i]=(pow[i-1]*p)%m;
            h[i]=(h[i-1]+(nums[i-1]+1)*pow[i-1])%m;
        }
        int ans=0;
        unordered_map<Hash, int,HashFunction, Equal> hs;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                Hash hash=(h[j+1]-h[i]+m)%m;
                hash=(hash*pow[n-j-1])%m;
                if(nums[j]%pp==0){cnt++;}
                if(cnt<=k && hs[hash]==0){
                    hs[hash]++;
                    ans++;
                }
            }
        }
        return ans;
    }
};