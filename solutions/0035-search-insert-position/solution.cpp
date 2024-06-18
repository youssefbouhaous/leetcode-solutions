class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target){
                return m;
            }
            if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        if(target<nums[0]){
            return 0;
        }
        return (l+r)/2+1;
    }
};