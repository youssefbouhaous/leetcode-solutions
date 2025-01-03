class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return false;
        map<int,int>mp;
        for(auto x:nums)mp[x]++;
        map<int,int>want;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]<=0){
                continue;
            }
            else if(want[nums[i]]){
                want[nums[i]]--;
                mp[nums[i]]--;
                want[nums[i]+1]++;
            }
            else if(mp[nums[i]+1] && mp[nums[i]+2]){
                mp[nums[i]]--;
                mp[nums[i]+1]--;
                mp[nums[i]+2]--;
                want[nums[i]+3]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};