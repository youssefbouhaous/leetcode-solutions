class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>v;
        v.push_back(0);
        int n=nums.size();
        bool f=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                v.push_back(0);
                f=1;
            }
            else{
                v[v.size()-1]++;
            }
        }
        int ans=v[0];
        for(int i=0;i<v.size()-1;i++){
            ans=max(ans,v[i]+v[i+1]);
        }
        if(f==1)
        return ans;

        return ans-1;
    }
};