class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        int n=nums.length;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int l=j+1;l<n;l++){
                    if(Math.abs(nums[i]+nums[j]+nums[l]-target)<Math.abs(target-ans)){
                        ans=nums[i]+nums[j]+nums[l];
                    }
                }
        return ans;
    }
}