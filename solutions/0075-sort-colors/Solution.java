class Solution {
    public void sortColors(int[] nums) {
        int r = 0;
        int b = 0;
        int w = 0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            int u = nums[i];
            r+=(u==0?1:0);
            w+=(u==1?1:0);
            b+=(u==2?1:0);
        }
        for(int i=0;i<n;i++){
            if(r-->0){
                nums[i]=0;
            }
            else if(w-->0){
                nums[i]=1;
            }
            else if(b-->0){
                nums[i]=2;
            }
        }
    }
}