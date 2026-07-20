class Solution {
    public long countBadPairs(int[] nums) {
        long n = nums.length;
        long ans = n*(n-1)/2;
        Map<Long,Long> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            if(mp.get(i-(long)nums[i])!=null){
                long mm = mp.get(i-(long)nums[i]);
                ans -= mm;
            }
            mp.put(i-(long)nums[i],mp.getOrDefault(i-(long)nums[i],0L)+1L);
        }
        return ans;
    }
}