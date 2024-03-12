class Solution {
    public int removeElement(int[] nums, int val) {
        int x=0;
        while(x<nums.length){
        int i=0;
        while(i<nums.length){
            if(nums[i]==val){
                for(int j=i+1;j<nums.length;j++){
                    int tmp=nums[j-1];
                    nums[j-1]=nums[j];
                    nums[j]=tmp;
                }
            }
            i++;
        }
        x++;
        }
        int c=0;
        for(int i=nums.length-1;i>-1;i--){
            if(nums[i]==val){
                c++;
            }
        }
        return nums.length-c;
    }
}