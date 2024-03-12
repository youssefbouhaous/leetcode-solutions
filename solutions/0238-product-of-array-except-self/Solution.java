class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n=nums.length;
        int[] pre = new int[n];
        int[] suf = new int[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i];
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>-1;i--){
            suf[i]=suf[i+1]*nums[i];
        }
        int[] res=new int[n];
        res[0]=suf[1];
        res[n-1]=pre[n-2];
        for(int i=1;i<n-1;i++){
            res[i]=pre[i-1]*suf[i+1];
        }
        return res;
    }
}