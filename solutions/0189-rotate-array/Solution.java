class Solution {
    public void rotate(int[] nums, int k) {
        int i=nums.length-1;
        int tmp=nums[nums.length-1];
        int[] old= new int[nums.length];
        for(int j=0;j<nums.length;j++){
            old[j]=nums[j];
        } 
        while(i>-1){
            nums[i]=old[(i-k%nums.length+nums.length)%nums.length];
            i--;
        }
        nums[(nums.length-1+k)%nums.length]=tmp;
    }
}