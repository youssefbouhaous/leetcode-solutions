class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int mx=1;
        map<int,int>mp;
        for(auto x:deck){
            mp[x]++;
            mx=max(mp[x],mx);
        }
        for(auto x:mp){
            mx=gcd(x.second,mx);
        }
        return mx!=1;
    }
};