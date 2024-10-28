class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<long long,bool>mp;
        for(auto x:nums){
            mp[x]=1;
        }
        int ans=-1;
        for(auto x:nums){
            int tmp=0;
            long long int p=x;
            while(mp.find(p)!=mp.end()){
                tmp++;
                p*=p;
            }
            if(tmp>1)
            ans=max(ans,tmp);
        }
        return ans;
    }
};