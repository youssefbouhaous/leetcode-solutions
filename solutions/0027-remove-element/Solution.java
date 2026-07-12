class Solution {
    public int removeElement(int[] nums, int val) {
        int n = nums.length;
        int ans = n;
        int o = n;
        while(o-->0)
        for(int i=0;i<n;i++){
            if(nums[i] == val){
                ans--;
                for(int j=i+1;j<n;j++){
                    nums[j-1]=nums[j];
                }
                if(ans>0)
                nums[ans]=-1;
            }
        }
        return ans;
    }
}