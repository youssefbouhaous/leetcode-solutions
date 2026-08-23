class Solution {
    public int waysToMakeFair(int[] nums) {
        int n =nums.length;
        int ans = 0;
        int o=0;
        int e=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                e+=nums[i];
            }else{
                o+=nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                e-=nums[i];
            }else{
                o-=nums[i];
            }
            if(e==o)ans++;
            if(i%2==0){
                o+=nums[i];
            }else{
                e+=nums[i];
            }
        }
        return ans;
    }
}