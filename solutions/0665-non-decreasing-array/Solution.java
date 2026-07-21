class Solution {
    public boolean checkPossibility(int[] nums) {
        int n = nums.length;
        if(n<3)return true;
        int id = -1;
        boolean f=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                f=false;break;
            }
        }
        if(f)return true;
        int r=-1;
        int l=-1;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                l=i;break;
            }
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]<nums[i-1]){
                r=i;break;
            }
        }
        if(l!=-1){
            int tmp=nums[l];
            nums[l]=nums[l+1];
            f=true;
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1]){
                    f=false;break;
                }
            }
            if(f)return true;
            nums[l]=tmp;
        }
        if(r!=-1){
            int tmp=nums[r];
            nums[r]=nums[r+1];
            f=true;
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1]){
                    f=false;break;
                }
            }
            if(f)return true;
            nums[r]=tmp;
        }
        int tmp=nums[0];
        nums[0]=nums[1];
        f=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                f=false;break;
            }
        }
        if(f)return true;
        nums[0]=tmp;
        nums[n-1]=nums[n-2];
        f=true;
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1]){
                    f=false;break;
                }
            }
            if(f)return true;
        return false;
    }
}