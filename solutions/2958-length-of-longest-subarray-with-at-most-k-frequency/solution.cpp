class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int cur=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        int o=0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]<k){
                mp[nums[i]]++;
                cur++;
                ans=max(ans,cur);
            }
            else{
                while(mp[nums[i]]>=k){
                    mp[nums[o]]--;
                    o++;
                    cur--;
                }
                cur++;
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};