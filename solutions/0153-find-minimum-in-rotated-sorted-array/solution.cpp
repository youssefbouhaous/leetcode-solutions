class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1]) return nums[0];
        if(n==2) return min({nums[0],nums[1]});
        if(nums[n-1]<nums[0] && nums[n-1] <nums[n-2]) return nums[n-1];
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(m<n && m>0 && nums[m]<nums[m-1] && nums[m]<nums[m+1]){
                return nums[m];
            }
            if(nums[m]<nums[0]) r=m-1;
            else l=m+1;
        }
        return nums[n-1];
    }
};