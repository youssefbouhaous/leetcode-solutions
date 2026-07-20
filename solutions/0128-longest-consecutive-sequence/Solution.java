class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        Set<Integer> st = new HashSet<>();
        for(int x:nums)st.add(x);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!st.contains(nums[i]) || st.contains(nums[i]-1))continue;
            int cnt=0;
            int cur = nums[i];
            while(st.contains(cur)){
                cnt++;
                st.remove(cur++);
            }
            ans = Math.max(ans,cnt);
        }
        return ans;
    }
}