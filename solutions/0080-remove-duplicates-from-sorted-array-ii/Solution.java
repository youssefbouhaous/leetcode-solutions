class Solution {
    public int removeDuplicates(int[] nums) {
        int k=1;
        int l=nums[0];
        int c=1;
        for(int i=1;i<nums.length;i++){
            if(c<2){
                nums[k]=nums[i];
                c++;
                if(nums[i]!=l){
                    l=nums[i];
                    c=1;
                }
                k++;
            }
            else if(nums[i]!=l){
                l=nums[i];
                nums[k]=nums[i];
                c=1;
                k++;
            }
        }
        return Math.min(k,nums.length);
    }
}