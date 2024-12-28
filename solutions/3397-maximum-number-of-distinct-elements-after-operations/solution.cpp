class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int last=INT_MIN;
        int n=nums.size();
        if(n==1)return 1;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int mn=nums[i]-k;
            int mx=nums[i]+k;
            if(last<mn){last=mn;ans++;}
            else if(last+1<=mx){
                ans++;
                last++;
            }
        }
        return ans;
    }
};