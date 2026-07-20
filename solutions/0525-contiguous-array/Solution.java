class Solution {
    public int findMaxLength(int[] nums) {
        int ans = 0;
        int n = nums.length;
        int[] pre = new int[n+1];
        Map<Integer,Integer> mp = new HashMap<>();
        mp.put(0,-1);
        for(int i=0;i<n;i++){
            if(nums[i]==0)nums[i]=-1;
            pre[i+1]=pre[i]+nums[i];
            if(mp.get(pre[i+1])!=null){
                ans=Math.max(ans,i-mp.get(pre[i+1]));
            }
            mp.putIfAbsent(pre[i+1],i);
        }
        return ans;
    }
}