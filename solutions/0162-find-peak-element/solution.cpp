class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        else if(n==2){
            if(nums[0]>nums[1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if((nums[0]>nums[1])){
            return 0;
        }
        else if((nums[n-1]>nums[n-2])){
            return n-1;
        }
        int r=n-1;
        int l=0;
        int m=(l+r)/2;
        while(l<=r){
            int m=(l+r)/2;
            if(m==0){
                if(nums[0]>nums[1]){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            if(m==n-1){
                if(nums[m]>nums[m-1]){
                    return m;
                }
                else{
                    return m-1;
                }
            }
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                return m;
            }
            if(nums[m]<nums[m+1]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return m;
    }
};