class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int t=0;
        for(int x:nums){
            t=(t+x)%p;
        }
        int tar=t%p;
        if(tar==0)return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int cur=0;
        int ans=n;
        for(int i=0;i<n;i++){
            cur=(cur+nums[i])%p;
            int needed=(cur-tar+p)%p;
            if(mp.find(needed)!=mp.end()){
                ans=min(i-mp[needed],ans);
            }
            mp[cur]=i;
        }
        return ans==n?-1:ans;
    }
};