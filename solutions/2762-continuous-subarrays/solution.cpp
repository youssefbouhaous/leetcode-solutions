class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        map<int,int>mp;
        int l=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            int mn=mp.begin()->first;
            int mx=mp.rbegin()->first;
            if(mx-mn<=2){
                ans+=(long long)(i-l+1);
            }
            else{
                while(mx-mn>2){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0){
                        mp.erase(nums[l]);
                    }
                    l++;
                    mn=mp.begin()->first;
                    mx=mp.rbegin()->first;
                }
                ans+=(long long)(i-l+1);
            }
        }
        return ans;
    }
};