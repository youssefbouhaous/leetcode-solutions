class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        for(int i=0;i<n;i++){
            nums[i] = (nums[i]+k)%k;
        }
        int[] pre = new int[n+1];
        Map<Integer,Integer> mp = new HashMap<>();
        mp.put(0,1);
        int ans=0;
        for(int i=0;i<n;i++){
            pre[i+1]=(pre[i]+nums[i]+k)%k;
            if(mp.get(pre[i+1])!=null){
                ans+=mp.get(pre[i+1]);
            }
            mp.put(pre[i+1],mp.getOrDefault(pre[i+1],0)+1);
        }
        return ans;
    }
}