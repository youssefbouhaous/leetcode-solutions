class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=nums.back()-nums[0];
        int n=nums.size();
        int ax=nums[n-4];
        int am=nums[0];
        for(int i=0;i<n-3;i++){
            ax=max(ax,nums[i]);
            am=min(am,nums[i]);
        }
        ans=min(ans,ax-am);
        ax=nums[n-3];
        am=nums[1];
        for(int i=1;i<n-2;i++){
            ax=max(ax,nums[i]);
            am=min(am,nums[i]);
        }
        
        ans=min(ans,ax-am);
        ax=nums[n-2];
        am=nums[2];
        for(int i=2;i<n-1;i++){
            ax=max(ax,nums[i]);
            am=min(am,nums[i]);
        }
        
        ans=min(ans,ax-am);
        ax=nums[n-2];
        am=nums[3];
        for(int i=3;i<n;i++){
            ax=max(ax,nums[i]);
            am=min(am,nums[i]);
        }
        
        ans=min(ans,ax-am);
        return ans;
    }
};