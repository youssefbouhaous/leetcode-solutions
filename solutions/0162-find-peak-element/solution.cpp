class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int r=nums.size()-1;
        int l=0;
        while(l<=r){
            int m=(l+r)/2;
            if((m==0 || nums[m]>nums[m-1]) && (m==nums.size()-1 || nums[m]>nums[m+1])){
                return m;
            }
            else if(nums[m]<nums[m+1]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return 0;
    }
};