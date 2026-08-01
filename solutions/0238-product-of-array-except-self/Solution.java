class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] prod = new int[n];
        int[] pre = new int[n+1];
        int[] suf = new int[n+1];
        pre[0]=1;suf[n]=1;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]*nums[i];
            suf[n-i-1]=suf[n-i]*nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            prod[i]=pre[i]*suf[i+1];
        }
        return prod;
    }
}